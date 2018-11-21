const express = require("express");
const router = express.Router();
const dateTime = require('../middleware/dateTime');

const UserController = require('../controllers/user');
const checkAuth = require('../middleware/check-auth');

/******************************************
* Get all users
* Method:
*   GET
* Input:
*   Nothing
* Usage:
*   ie- localhost:3000/user/
*******************************************/
router.get("/", UserController.users_get_all);


/******************************************
* Get all users by location
* Method:
*   GET
* Input:
*   location
* Usage:
*   ie- localhost:3000/user/usersLocation
*******************************************/
router.get("/usersLocation", UserController.users_get_all_by_location);


/******************************************
* Get single user
* Method:
*   GET
* Input:
*   user._id as a parameter in url.
* Usage:
*   ie- localhost:3000/user/5beee3e0a0539d08981a2707
*******************************************/
router.get("/:userId", UserController.userDetail);



/******************************************
* create a user account
* Method:
*   POST
* Requirements: 
*      username: String, 
*      email: String,
*      password: String
* Middleware:
*   dateTime -> provides req.currentDateTime value
* Restrictions:
*  --> duplication check against email
*  --> duplication check against username
* Usage:
*   ie- localhost:3000/user/createAccount
*******************************************/
router.post("/createAccount", dateTime, UserController.createAccount);

/******************************************
* User login
* Method:
*   POST
* Input:
*   
* Middleware:
*   dateTime -> provides req.currentDateTime value 
* Usage:
*   ie- localhost:3000/user/login
*******************************************/
router.post("/login", dateTime, UserController.user_login);


/******************************************
* Update single user
* Method:
*   PATCH
* Input:
*   user._id as a parameter in url.
* Middleware:
*   dateTime -> provides req.currentDateTime value
* Usage:
*   ie- localhost:3000/user/5beee3e0a0539d08981a2707
*******************************************/
router.patch('/:userId', dateTime, UserController.update_user);


/******************************************
* Delete single user
* Method:
*   DELETE
* Input:
*   user._id as a parameter in url.
* RESTRICTIONS
*  requires user to be signed in,
*  *** token is required to be sent in headers ****
*  will eventually have more restrictions
*  imposed, ie- user level etc.
* Usage: 
*   header value:
*   key: Authorization value: Bearer theTokenValue
*   url:
*   ie- localhost:3000/user/5beee3e0a0539d08981a2707
*******************************************/
router.delete("/:userId", checkAuth, UserController.user_delete);

module.exports = router;