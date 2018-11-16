const express = require("express");
const router = express.Router();

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
* Restrictions:
*  --> duplication check against email
*  --> duplication check against username
* Usage:
*   ie- localhost:3000/user/createAccount
*******************************************/
router.post("/createAccount", UserController.createAccount);



/******************************************
* User login
* Method:
*   POST
* Input:
*   user._id as a parameter in url. 
* Usage:
*   ie- localhost:3000/user/login
*******************************************/
router.post("/login", UserController.user_login);


/******************************************
* Update single user
* Method:
*   PATCH
* Input:
*   user._id as a parameter in url. 
*   ie- localhost:3000/user/5beee3e0a0539d08981a2707
*******************************************/
router.patch('/:userId', UserController.update_user);


/******************************************
* Delete single user
* Method:
*   DELETE
* Input:
*   user._id as a parameter in url. 
*   ie- localhost:3000/user/5beee3e0a0539d08981a2707
*******************************************/
router.delete("/:userId", UserController.user_delete);

module.exports = router;