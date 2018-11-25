//datelineentry route
// required libraries
const express = require('express');
const router = express.Router();
const checkAuth = require('../middleware/check-auth');
const dateTime = require('../middleware/dateTime');

const DateLineEntryController = require('../controllers/dateLineEntry');

/******************************************
* create dateLineEntries
* Method:
*   GET
* Input:
*   LineEntryfields: 
        date: (date._id)
        location: (location._id)
        name: string
        comments: string
        rating: number
* Middleware:
*   dateTime -> provides req.currentDateTime value
* Usage:
*   ie- localhost:3000/dateLineEntry/
*******************************************/
router.post("/", dateTime, DateLineEntryController.dateLineEntry_create);

/******************************************
* Get date dateLineEntries
* Method:
*   GET
* Input:
*   date._id as a parameter in url.
* Usage:
*   ie- localhost:3000/dateLineEntry/5beee3e0a0539d08981a2707
*******************************************/
router.get("/:dateId",  DateLineEntryController.dateLineEntry_getEntries);

/******************************************
* Update single dateLineEntry
* Method:
*   PATCH
* Input:
    dateLineEntry._id
*   date._id
*   comments
* Middleware:
*   dateTime -> provides req.currentDateTime value
* Usage:
*   ie- localhost:3000/dateLineEntry/
*******************************************/
router.patch("/", dateTime, DateLineEntryController.update_dateLineEntry);


/******************************************
* Delete single dateLineEntry
* Method:
*   DELETE
* Input:
*   dateLineEntry._id as a parameter in url. 
* Usage:
*   ie- localhost:3000/dateLineEntry/5beee3e0a0539d08981a2707
* RESTRICTIONS
*  requires user to be signed in,
*  will eventually have more restrictions
*  imposed, ie- user level etc.
*******************************************/
//router.delete('/:dateLineEntryId', checkAuth, DateLineEntryController.dateLineEntry_delete);
router.delete('/:dateLineEntryId', DateLineEntryController.dateLineEntry_delete);           //used for testing

module.exports = router;