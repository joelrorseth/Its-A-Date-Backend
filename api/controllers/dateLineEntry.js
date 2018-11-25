//Entry for dates
const mongoose = require("mongoose");

const myDate = require("../models/date");
const DateLineEntry = require("../models/dateLineEntry");


/*****************************************
 * Create a new date line entry
 * RETURNS
 *  dateLineEntry: created dateLineEntry ARRAY
 *  message
 *  error upon failure
 * NOTE
 *  must be registered user to create date
 *****************************************/
exports.dateLineEntry_create = (req, res, next) => {
    //console.log(JSON.stringify(req.body) + " is req.body");
    const newDateLineEntry = new DateLineEntry({
        _id: mongoose.Types.ObjectId(),
        date: req.body.date,            // a date id.
        location: req.body.location,    // a location id. 
        name: req.body.name,
        rating: req.body.rating,
        comments: req.body.comments,
        dateCreated: req.currentDateTime,
        dateUpdated: req.currentDateTime,
      });
    newDateLineEntry
        .save()
        .then(result1 => {
            //console.log(result1);
            DateLineEntry.find({date: req.body.date})
                .select("_id date location name rating comments dateCreated dateUpdated")
                .populate( " location ", "name address rating place_id dateCreated dateLastReferenced")
                .exec()
                .then(result => {
                    res.status(201).json({
                        dateLineEntry: result,
                        message: "dateLineEntry created"
                    });
                })
                .catch(err => {
                    //console.log(err);
                    res.status(500).json({
                      error: err
                    });
                });
        })
        .catch(err => {
            res.status(400).json({
                err: err,
                message: "Line Entry Creation fail."
            });
        });

};

exports.dateLineEntry_getEntries = (req, res, next) => {
    const date_id = req.params.dateId;
    DateLineEntry.find({date: date_id })
    .select("_id date location name rating comments dateCreated dateUpdated")
    .populate( " location ", "name address rating place_id dateCreated dateLastReferenced")
    .exec()
    .then(result => {
        res.status(201).json({
            count: result.length,
            dateLineEntry: result,
            message: "DateLineEntries for date " + date_id
        });
    })
    .catch(err => {
        //console.log(err);
        res.status(500).json({
          error: err
        });
    });
};

/*****************************************
 * Update a dateLineEntry by _id
 * RETURNS
 *  dateLineEntr(y/ies): updated dateLineEntry info for that date
 *  message
 *  updated information
 *  error upon failure
 *****************************************/
exports.update_dateLineEntry = (req, res, next) => {
    const id = req.body._id;
    const date = req.body.date;
    // set up the update object
    const updatedDateLineEntry = new DateLineEntry({
        date: date,
        location: req.body.location,
        name: req.body.name,
        rating: req.body.rating,
        comments: req.body.comments,
        dateUpdated: req.currentDateTime
    });
    /* deprecated function */
    DateLineEntry.findByIdAndUpdate( id,  updatedDateLineEntry )
      .exec()
      .then(result => {
        DateLineEntry.find({ date: date })
          .select("_id date location name rating comments dateCreated dateUpdated")
          .populate( " location ", "name address rating place_id dateCreated dateLastReferenced")
          .exec()
          .then(date => {
            // CHECK IF ARRAY IS >= 1
            if (date.length >= 1) {
              return res.status(200).json({
                date: date,
                message: "Date updated",
              });
            } 
          })
      })
      .catch(err => {
        //console.log(err);
        res.status(500).json({
          error: err
        });
      }); 
  };

  /*****************************************
 * Delete DateLineEntry
 * RETURNS
 *  message
 *  error upon failure
 * RESTRICTIONS
 *  requires user to be signed in,
 *  will eventually have more restrictions
 *  imposed, ie- user level etc.
 *****************************************/
exports.dateLineEntry_delete = (req, res, next) => {
    const dLE = req.params.dateLineEntryId;
    DateLineEntry.deleteOne({ _id: dLE })
    .exec()
    .then(result => {
      console.log(result);
      res.status(200).json({
        message: "DateLineEntry deleted.",
      });
    })
    .catch(err => {
      res.status(500).json({
        error: err
      });
    });
};
