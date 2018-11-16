const express = require("express");
const router = express.Router();

const UserController = require('../controllers/user');
const checkAuth = require('../middleware/check-auth');

// 
// return list of all users
router.get("/", UserController.users_get_all);

//******************************
// get single user info, only after sucessful login
//****************************** */
router.get("/:userId", UserController.userDetail);

//******************************
// create a user account
// Requirements: 
//      username: String, 
//      email: String,
//      password: String
// Restrictions:
//  --> duplication check against email
//  --> duplication check against username
//****************************** */
router.post("/createAccount", UserController.createAccount);

//****************************** */
// login function
// requires 
router.post("/login", UserController.user_login);

router.delete("/:userId", checkAuth, UserController.user_delete);

module.exports = router;