const express = require('express');
const router = express.Router();
const mongoose = require('mongoose');
const checkAuth = require('../middleware/check-auth');

const Order = require('../models/order');       // note no extension
const Product = require('../models/product');   // used to check for valid product.

const OrdersController = require('../controllers/orders');

// for protected routes, check the token with middleware and only continue if it has not been messed with.
// checkAuth must stay in the routes file for this set up as checking(don't move to controller)

router.get("/", OrdersController.orders_get_all);

router.post("/", checkAuth, OrdersController.orders_create_order);

//use colon to create variable from express
router.get("/:orderId", checkAuth, OrdersController.orders_get_order);

router.delete("/:orderId", checkAuth, OrdersController.orders_delete_order);

module.exports = router;

