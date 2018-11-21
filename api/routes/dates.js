// required libraries
const express = require('express');
const router = express.Router();
const mongoose = require('mongoose');
const checkAuth = require('../middleware/check-auth');
const dateTime = require('../middleware/dateTime');

//const user = require('../models/user');       // note no extension
//const Product = require('../models/product');   // used to check for valid product.

const DatesController = require('../controllers/dates');

/******************************************
* Get all dates
* Method:
*   GET
* Input:
*   Nothing
* Middleware:
*   dateTime -> provides req.currentDateTime value
* Usage:
*   ie- localhost:3000/dates/
*******************************************/
router.get("/", dateTime, DatesController.dates_get_all);

/******************************************
* create a new Date
* Method:
*   POST
* Requirements: 
*      (user) _id: String, 
*      comments: String,
* Middleware:
*   dateTime -> provides req.currentDateTime value
* Restrictions:
*  --> user's _id must exist in database.
* Usage:
*   ie- localhost:3000/dates/
*******************************************/
router.post("/", dateTime, DatesController.dates_create_date);

/******************************************
* Get single date
* Method:
*   GET
* Input:
*   date._id as a parameter in url.
* Usage:
*   ie- localhost:3000/dates/5beee3e0a0539d08981a2707
*******************************************/
router.get("/:dateId",  DatesController.dates_get_date);

/******************************************
* Update single date
* Method:
*   PATCH
* Input:
*   date._id
*   comments
* Middleware:
*   dateTime -> provides req.currentDateTime value
* Usage:
*   ie- localhost:3000/dates/
*******************************************/
router.patch("/", dateTime, DatesController.update_date);

/******************************************
* Delete single date
* Method:
*   DELETE
* Input:
*   date._id as a parameter in url. 
* Usage:
*   ie- localhost:3000/dates/5beee3e0a0539d08981a2707
* RESTRICTIONS
*  requires user to be signed in,
*  will eventually have more restrictions
*  imposed, ie- user level etc.
*******************************************/
router.delete("/:dateId", checkAuth, DatesController.dates_delete_date);
//router.delete("/:dateId", DatesController.dates_delete_date);     // used without restriction for testing

module.exports = router;