//required libraries
const mongoose = require("mongoose");

const myDate = require("../models/date");
const User = require("../models/user");


/*****************************************
 * Create a new date by user
 * RETURNS
 *  date: created date object
 *  message
 *  error upon failure
 * NOTE
 *  must be registered user to create date
 *****************************************/
exports.dates_create_date = (req, res, next) => {
  User.findById(req.body._id)
    .then(user => {
      if (!user) {
        return res.status(404).json({
          message: "You must be a registered user to comment."
        });
      }
      const date = new myDate({
        _id: mongoose.Types.ObjectId(),
        nameDate: req.body.nameDate,
        comments: req.body.comments,
        city: req.body.city,
        dateCreated: req.currentDateTime,
        dateUpdated: req.currentDateTime,
        user: req.body._id
      });
      return date.save();
    })
    .then(result => {
      //console.log(result);
      res.status(201).json({
        message: "New date stored",
        createdDate: result,
        request: {
          type: "GET",
          url: "http://localhost:3000/dates/" + result._id
        }
      });
    })
    .catch(err => {
      console.log(err);
      res.status(500).json({
        error: err
      });
    });
};


/********************************
 * Gets All dates
 * RETURNS:
 *  Date: ARRAY of all dates with all details 
 *  Count: length of the array
 *  Message
 *  Error upon failure
 ********************************/
exports.dates_get_all = (req, res, next) => {
  console.log(req.currentDateTime);
  myDate.find()
    .select("user _id nameDate city comments dateCreated dateUpdated")
    .populate("user", "_id userName email nameFirst nameLast" )
    .exec()
    .then(docs => {
      res.status(200).json({
        count: docs.length,
        dates: docs.map(doc => {
          return {
            _id: doc._id,
            user: doc.user,
            nameDate: doc.nameDate,
            city: doc.city,
            comments: doc.comments,
            dateCreated: doc.dateCreated,
            dateUpdated: doc.dateUpdated,
            request: {
              type: "GET",
              url: "http://localhost:3000/dates/" + doc._id
            }
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




/*****************************************
 * Find a date by _id
 * RETURNS
 *  message
 *  date information
 *  error upon failure
 *****************************************/
exports.dates_get_date = (req, res, next) => {
  myDate.findById(req.params.dateId)
    .populate("user", "_id userName nameDate city email nameFirst nameLast")
    .exec()
    .then(date => {
      if (!date) {
        return res.status(404).json({
          message: "Date not found"
        });
      }
      res.status(200).json({
        date: date,
        request: {
          type: "GET",
          url: "http://localhost:3000/dates"
        }
      });
    })
    .catch(err => {
      res.status(500).json({
        error: err
      });
    });
};

/*****************************************
 * Update a date by _id
 * RETURNS
 *  date: updated date info
 *  message
 *  updated user information
 *  error upon failure
 *****************************************/
exports.update_date = (req, res, next) => {
  const id = req.body._id;
  // set up the update object
  const updatedDate = new myDate({
      comments: req.body.comments,
      nameDate: req.body.nameDate,
      city: req.body.city,
      dateUpdated: req.currentDateTime
  });
  /* deprecated function */
  myDate.findByIdAndUpdate( id,  updatedDate )
    .exec()
    .then(result => {
      myDate.find({ _id: result._id })
        .select("_id user comments nameDate city dateCreated dateUpdated")
        .populate("user", "_id userName email nameFirst nameLast")
        .exec()
        .then(date => {
          // CHECK IF ARRAY IS >= 1
          if (date.length >= 1) {
            return res.status(200).json({
              date: date,
              message: "Date updated",
              request: {
                type: "GET",
                url: "http://localhost:3000/dates/" + id 
              }
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
 * Delete Date
 * RETURNS
 *  message
 *  error upon failure
 * RESTRICTIONS
 *  requires user to be signed in,
 *  will eventually have more restrictions
 *  imposed, ie- user level etc.
 *****************************************/
exports.dates_delete_date = (req, res, next) => {
  //console.log(req.params.dateId);
  myDate.deleteOne({ _id: req.params.dateId })
    .exec()
    .then(result => {
      console.log(result);
      res.status(200).json({
        message: "Date deleted.",
        request: {
          type: "POST",
          url: "http://localhost:3000/dates",
        }
      });
    })
    .catch(err => {
      res.status(500).json({
        error: err
      });
    });
};