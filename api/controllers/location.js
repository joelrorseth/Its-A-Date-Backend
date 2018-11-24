//Location file
const mongoose = require("mongoose");
const Location = require("../models/location");


/********************************
 * Gets All locations
 * RETURNS:
 *  location: ARRAY of all locations
 *  Count: length of the array
 *  Message
 *  Error upon failure
 ********************************/
exports.location_get_all = (req, res, next) => {
  Location.find()
    .exec()
    .then(docs => {
      res.status(200).json({
        count: docs.length,
        locations: docs.map(doc => {
          return {
            _id: doc._id, 
            place_id: doc.place_id,
            name: doc.name,
            address: doc.address,
            rating: doc.rating,
            dateCreated: doc.dateCreated,
            dateLastReferenced: doc.dateLastReferenced
          };
        })
      });
    })
    .catch(err => {
      res.status(500).json({
        error: err
      });
    });
};


/********************************
 * Gets single location
 * RETURNS:
 *  location: ARRAY with one location 
 *  Message
 *  Error upon failure
 ********************************/
exports.locationDetail = (req, res, next) => {
  const id = req.params.locationId;
  const updatedLocation = new Location({
    dateLastReferenced: req.currentDateTime
  });
  /* deprecated function */
  Location.findByIdAndUpdate( id,  updatedLocation )
    .exec()
    .then(result => {
      Location.find({ _id: result._id })
        .select("_id place_id name address rating dateCreated dateLastReferenced")
        .exec()
        .then(location => {
          // CHECK IF ARRAY IS >= 1
          if (location.length >= 1) {
            return res.status(200).json({
              location: location,
              message: "Date referenced updated and returned single result",
            });
          } 
        })
    })
    .catch(err => {
      console.log(err);
      res.status(500).json({
        error: err
      });
    });
};



/*****************************************
 * Create a location
 * RETURNS
 *  location that was created
 *  message
 *  error upon failure
 *****************************************/
exports.createLocation = (req, res, next) => {
    //when using find like this...
    /* FIND WILL RETURN AN EMPTY ARRAY!!! NOT NULL */
    // search to see if the place_id exists in the location DB
    // don't allow duplicates
    Location.find({ place_id: req.body.place_id})
    .exec()
    .then(alocation => {
      if(alocation.length >= 1) {
        return res.status(409).json({
          message: "Location exists!"
        });
      }
      Location.find()
        .exec()
        .then(locations => {
          // CHECK IF ARRAY IS >= 10 or allow more entries.
          if (locations.length === 10) {
              let oldestDate = req.currentDateTime;
              let delete_id = "";
              const locationArray = locations.map(local => {
                  return {
                      _id: local._id, 
                      place_id: local.place_id,
                      name: local.name,
                      address: local.address,
                      rating: local.rating,
                      dateCreated: local.dateCreated,
                      dateLastReferenced: local.dateLastReferenced
                  }
              })
              locationArray.forEach( function(item){
                  if(Date.parse(oldestDate) > Date.parse(item.dateLastReferenced)){
                      oldestDate = item.dateLastReferenced;
                      delete_id = item._id;
                  }
                  // i will try to fix this later. will get the other parts working. 
                  // if(item.place_id == req.body.place_id){
                  //     return res.status(409).json({
                  //       message: "Location exists!"
                  //     });
                  // }
              });
              //console.log(delete_id + " is delete_id");
              Location.remove({_id: delete_id})
              .exec()
              .then(result => {
                  const addLocation = new Location({
                      _id: new mongoose.Types.ObjectId(), 
                      place_id: req.body.place_id,
                      name: req.body.name,
                      address: req.body.address,
                      rating: req.body.rating,
                      dateCreated: req.currentDateTime,
                      dateLastReferenced: req.currentDateTime
                  });
                  addLocation
                      .save()
                      .then(result => {
                          res.status(201).json({
                              location: result,
                              message: "****WARNING**** Location saved and old location removed."
                          })
                      })
              })
              .catch(err => {
                console.log(err);
                res.status(500).json({
                  error: err
                });
              });
          // less than 10 entries. just add element. 
          } else {
              const addLocation = new Location({
                  _id: new mongoose.Types.ObjectId(), 
                  place_id: req.body.place_id,
                  name: req.body.name,
                  address: req.body.address,
                  rating: req.body.rating,
                  dateCreated: req.currentDateTime,
                  dateLastReferenced: req.currentDateTime
              });
              addLocation
                  .save()
                  .then(result => {
                      res.status(201).json({
                          location: result,
                          message: "Location saved, nothing deleted."
                      })
                  })
                  .catch(err => {
                      console.log(err);
                      res.status(500).json({
                        error: err
                      });
                  });
          }
        })
        .catch(err => {
            console.log(err);
            res.status(500).json({
              error: err
            });
        });
  });
};



/*****************************************
 * Delete location
 * RETURNS
 *  message
 *  error upon failure
 * RESTRICTIONS
 *  requires user to be signed in,
 *  will eventually have more restrictions
 *  imposed, ie- user level etc.
 *****************************************/

exports.location_delete = (req, res, next) => {
  Location.remove({ _id: req.params.locationId })  
    .exec()
    .then(result => {
      res.status(200).json({
        message: "Location deleted"
      });
    })
    .catch(err => {
      console.log(err);
      res.status(500).json({
        error: err
      });
    });
};