const mongoose = require("mongoose");
const bcrypt = require("bcrypt");
const jwt = require("jsonwebtoken");

const User = require("../models/user");


/**
 *  return list of all users
 **/
exports.users_get_all = (req, res, next) => {
  console.log("get all");
  User.find()
    .select("email _id")
    .exec()
    .then(docs => {
      res.status(200).json({
        count: docs.length,
        users: docs.map(doc => {
          return {
            _id: doc._id,
            email: doc.email

            // request: {
            //   type: "GET",
            //   url: "http://localhost:3000/orders/" + doc._id
            // }
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

exports.userDetail = (req, res, next) => {
  //check to see if user is in the DB
  //when using find like this...
  /* FIND WILL RETURN AN EMPTY ARRAY!!! NOT NULL */
  User.find({ userName: req.body.userName })
    .select("_id userName email nameFirst nameLast phone gender sexualOrientation relationshipStatus age city")
    .exec()
    .then(user => {
      console.log(req.params.userName);
      console.log(req.body.userName + " is body username");
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



/**
 * Create a user account
 **/
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
                age: ""

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

exports.user_login = (req, res, next) => {
  User.find({ email: req.body.email })
    .exec()
    .then(user => {
      if (user.length < 1) {
        return res.status(401).json({
          message: "Auth failed"
        });
      }
      console.log(user);
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
              expiresIn: "1h"
            }
          );
          return res.status(200).json({
            message: "Auth successful",
            token: token
          });
        }
        res.status(401).json({
          message: "Auth failed"
        });
      });
    })
    .catch(err => {
      console.log(err);
      res.status(500).json({
        error: err
      });
    });
};

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