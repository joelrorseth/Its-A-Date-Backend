const mongoose = require("mongoose");
const bcrypt = require("bcrypt");
const jwt = require("jsonwebtoken");
const bodyParser = require('body-parser');
const User = require("../models/user");


/********************************
 * Gets All users
 * RETURNS:
 *  User: ARRAY of all users with all details except password
 *  Count: length of the array
 *  Message
 *  Error upon failure
 ********************************/
exports.users_get_all = (req, res, next) => {
  //console.log("get all");
  User.find()
    .select("email _id userName phone nameFirst nameLast gender sexualOrientation relationshipStatus city age dateCreated dateUpdated dateLastLogin")
    .exec()
    .then(docs => {
      res.status(200).json({
        count: docs.length,
        users: docs.map(doc => {
          return {
            _id: doc._id,
            email: doc.email,
            userName: doc.userName,
            phone: doc.phone,
            nameFirst: doc.nameFirst,
            nameLast: doc.nameLast,
            gender: doc.gender,
            sexualOrientation: doc.sexualOrientation,
            relationshipStatus: doc.relationshipStatus,
            city: doc.city,
            age: doc.age,
            dateCreated: doc.dateCreated,
            dateUpdated: doc.dateUpdated,
            dateLastLogin: doc.dateLastLogin,
            request: {
              type: "GET",
              url: "http://localhost:3000/user/" + doc._id
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


/********************************
 * Gets single user details
 * RETURNS:
 *  User: ARRAY with one user 
 *  Message
 *  Error upon failure
 ********************************/
exports.userDetail = (req, res, next) => {
  //console.log("user by id single.");
  User.find({ _id: req.params.userId })
    .select("_id userName email nameFirst nameLast phone gender sexualOrientation relationshipStatus age city dateCreated dateUpdated dateLastLogin")
    .exec()
    .then(user => {
      console.log(req.params.userId);
      console.log(user);
      // CHECK IF ARRAY IS >= 1
      if (user.length >= 1) {
        return res.status(200).json({
          user: user,
          message: "User Details"
        });
      } 
    })
    .catch(err => {
      console.log(err);
      res.status(500).json({
        error: err
      });
  });
};

/********************************
 * Gets All users BY LOCATION
 * RETURNS:
 *  User: ARRAY of all users with all details except password
 *  Count: length of the array
 *  Message
 *  Error upon failure
 ********************************/
exports.users_get_all_by_location = (req, res, next) => {
  console.log("get all by location");
  User.find({city: req.body.city})
    .select("email _id userName phone nameFirst nameLast gender sexualOrientation relationshipStatus city age dateCreated dateUpdated dateLastLogin")
    .exec()
    .then(docs => {
      res.status(200).json({
        count: docs.length,
        users: docs.map(doc => {
          return {
            _id: doc._id,
            email: doc.email,
            userName: doc.userName,
            phone: doc.phone,
            nameFirst: doc.nameFirst,
            nameLast: doc.nameLast,
            gender: doc.gender,
            sexualOrientation: doc.sexualOrientation,
            relationshipStatus: doc.relationshipStatus,
            city: doc.city,
            age: doc.age,
            dateCreated: doc.dateCreated,
            dateUpdated: doc.dateUpdated,
            dateLastLogin: doc.dateLastLogin,
            request: {
              type: "GET",
              url: "http://localhost:3000/user/" + doc._id
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
 * Create a user account
 * RETURNS
 *  message
 *  error upon failure
 * NOTE
 *  doesn't automatically sign user in. 
 *  user required to sign in after.
 *****************************************/
exports.createAccount = (req, res, next) => {
    //check to see if user is in the DB
    //when using find like this...
    /* FIND WILL RETURN AN EMPTY ARRAY!!! NOT NULL */
  User.find({userName: req.body.userName})
    .exec()
    .then(auser => {
      if(auser.length >= 1) {
        return res.status(409).json({
          message: "User exists!"
        });
      }
    User.find({ email: req.body.email })
      .exec()
      .then(user => {
        // CHECK IF ARRAY IS >= 1
        if (user.length >= 1) {
          return res.status(409).json({
            message: "Mail exists"
          });
        } else {
          bcrypt.hash(req.body.password, 10, (err, hash) => {
            if (err) {
              return res.status(500).json({
                error: err
              });
            } else {
              const user = new User({
                _id: new mongoose.Types.ObjectId(),
                email: req.body.email,
                userName: req.body.userName,
                password: hash,
                phone: "",
                nameFirst: "",
                nameLast: "",
                gender: "",
                sexualOrientation: "",
                relationshipStatus: "",
                city: "",
                age: "",
                dateCreated: req.currentDateTime,
                dateUpdated: req.currentDateTime,
                dateLastLogin: req.currentDateTime,

              });
              user
                .save()
                .then(result => {
                  console.log(result);
                  res.status(201).json({
                    message: "User created"
                  });
                })
                .catch(err => {
                  console.log(err);
                  res.status(500).json({
                    error: err
                  });
                });
            }
          });
        }
      });
    });
};


/*****************************************
 * User log in
 * RETURNS
 *  message
 *  token for session on server (2hr expiry)
 *  error upon failure
 * NOTE
 *  doesn't automatically sign user in. 
 *  user required to sign in after.
 *****************************************/
exports.user_login = (req, res, next) => {
  User.find({ userName: req.body.userName })
    .exec()
    .then(user => {
      if (user.length < 1) {
        return res.status(401).json({
          message: "Auth failed"
        });
      }
      //console.log(user);
      bcrypt.compare(req.body.password, user[0].password, (err, result) => {
        if (err) {
          return res.status(401).json({
            message: "Auth failed"
          });
        }
        if (result) {
          // also go into your nodemon.json file and add the global environment variable (JWT_KEY)
          const token = jwt.sign(
            {
              email: user[0].email,
              userId: user[0]._id
            },
            process.env.JWT_KEY,
            {
              expiresIn: "2h"
            }
          );
          const updateduser = new User({
            dateLastLogin: req.currentDateTime
          });
          // update login field for user.
          User.findByIdAndUpdate( user[0]._id,  updateduser )
            .exec()
            .then(result => {
              console.log(result);
              return res.status(200).json({
                message: "Auth successful",
                //user: result,   // used for testing. don't send back all user info.
                token: token
              });
            })
            .catch(err =>{
              res.status(401).json({
                err: err,
                message: "Auth failed"
              });
            });  
          }
      });
  });
};


/*****************************************
 * Update a user by _id
 * RETURNS
 *  message
 *  updated user information
 *  error upon failure
 *****************************************/
exports.update_user = (req, res, next) => {
  const id = req.params.userId;
  // set up the update object
  const updateduser = new User({
      phone: req.body.phone,
      nameFirst: req.body.nameFirst,
      nameLast: req.body.nameLast,
      gender: req.body.gender,
      sexualOrientation: req.body.sexualOrientation,
      relationshipStatus: req.body.relationshipStatus,
      city: req.body.city,
      age: req.body.age,
      dateUpdated: req.currentDateTime
  });
  //console.log(updateduser);
  //console.log(id + " is id ");
      /* trying to sort this out but not getting it to work properly.*/
  // try{
  // User.findOneAndUpdate(
  //   {"id": id },
  //   { $set: { "phone" : updateduser.phone, "gender" : updateduser.gender } },
  //   { returnNewDocument: true }
  //   );
  // }
  // catch(e){
  //   print(e);
  // }
  /* deprecated function */
  User.findByIdAndUpdate( id,  updateduser )
    .exec()
    .then(result => {
      User.find({ _id: result._id })
        .select("_id userName email nameFirst nameLast phone gender sexualOrientation relationshipStatus age city")
        .exec()
        .then(user => {
          // CHECK IF ARRAY IS >= 1
          if (user.length >= 1) {
            return res.status(200).json({
              user: user,
              message: "User updated",
              request: {
                type: "GET",
                url: "http://localhost:3000/user/" + id 
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
 * Delete User
 * RETURNS
 *  message
 *  error upon failure
 * RESTRICTIONS
 *  requires user to be signed in,
 *  will eventually have more restrictions
 *  imposed, ie- user level etc.
 *****************************************/

exports.user_delete = (req, res, next) => {
  User.remove({ _id: req.params.userId })  // use userId since that is param specified in function call from Routes/user.js
    .exec()
    .then(result => {
      res.status(200).json({
        message: "User deleted"
      });
    })
    .catch(err => {
      console.log(err);
      res.status(500).json({
        error: err
      });
    });
};