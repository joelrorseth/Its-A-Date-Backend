//location route
// required libraries
const express = require('express');
const router = express.Router();
const checkAuth = require('../middleware/check-auth');
const dateTime = require('../middleware/dateTime');

const LocationController = require('../controllers/location');

/******************************************
* Get all locations
* Method:
*   GET
* Input:
*   Nothing
* Middleware:
*   dateTime -> provides req.currentDateTime value
* Usage:
*   ie- localhost:3000/location/
*******************************************/
router.get("/", dateTime, LocationController.location_get_all);

/******************************************
* create a new Date
* Method:
*   POST
* Requirements: 
*      (google) place_id: String, 
* Middleware:
*   dateTime -> provides req.currentDateTime value
* Restrictions:
*  --> user's _id must exist in database.
* Usage:
*   ie- localhost:3000/location/
*******************************************/
router.post("/", dateTime, LocationController.createLocation);

/******************************************
* Get single date
* Method:
*   GET
* Input:
*   location._id as a parameter in url.
* Usage:
*   ie- localhost:3000/location/5beee3e0a0539d08981a2707
*******************************************/
router.get("/:locationId",  dateTime, LocationController.locationDetail);

/******************************************
* Delete single location
* Method:
*   DELETE
* Input:
*   location._id as a parameter in url. 
* Usage:
*   ie- localhost:3000/location/5beee3e0a0539d08981a2707
* Middleware:
*   checkAuth -> checks token
* RESTRICTIONS
*  requires user to be signed in,
*  will eventually have more restrictions
*  imposed, ie- user level etc.
*******************************************/
router.delete("/:locationId", checkAuth, LocationController.location_delete);
//router.delete("/:locationId", LocationController.location_delete);     // used without restriction for testing

module.exports = router;