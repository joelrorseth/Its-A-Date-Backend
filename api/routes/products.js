const express = require('express');
const router = express.Router();
const mongoose = require('mongoose');
const multer = require('multer');
const checkAuth = require('../middleware/check-auth');
const ProductsController = require('../controllers/products');

const storage = multer.diskStorage({
    destination: function(req, file, cb){
        cb(null, './uploads/'); // first element is the error (no error if uploads!)
    },
    filename: function(req, file, cb){
        cb(null, new Date().toISOString() + file.originalname);
    }
});

const fileFilter = (req, file, cb) => {
    //reject a file
    if ( file.mimetype === 'image/jpg' || file.mimetype === 'image/png' || file.mimetype === 'image/jpeg'){
        cb(null, true);                         // edit this 1st param if you want to throw error when image upload fail.
    } else {
        cb(new Error('bad format'), false);     //like this.
    }
 

};
//const upload = multer({ dest: 'uploads/'});    // must set up folder to be statically available in app.js 
const upload = multer({
    storage: storage, 
    limits: {
        fileSize: 1024 * 1024 * 5
    }, 
    fileFilter: fileFilter
});       // using info above about storage options.

//import product model from the model file. 
// use this to work on database data and set it's schema.
const Product = require('../models/product');

// this works for all products
router.get('/', ProductsController.products_get_all);

// this works for all products
// by setting up upload on line 5, you can use it as middleware in the post call now.
// watch order, upload.single will parse the form data and load the middleware, but putting check auth before causes error. **/
// want to send token as part of header, not in the body. **/
// sent in header as type Authorization: Bearer token_value
router.post('/', checkAuth, upload.single('productImage'), ProductsController.products_create_product );
    // name and price will need documentation saying the post request requires that data in public documents
    // valid json data will be in string format.
    /*  ie-
            {
                "name": "Joe Smo",
                "price": "12.39"
            }
    */
    //local copy of a product that we created to test with.
    // const product = {
    //     name: req.body.name,
    //     price: req.body.price
    // }



// setting up with express as a constant by using colon for looking up single ID's.
router.get('/:productID', ProductsController.products_get_product);

    // used when not using the MongoDB
    // if(id === 'special'){
    //     res.status(200).json({
    //         message: 'You have the special id',
    //         id: id
    //     });
    // } else {
    //     res.status(200).json({
    //         message: 'You have passed an ID',
    //         id: id
    //     });
    // }


router.patch('/:productID', checkAuth, ProductsController.products_update_product);

router.delete('/:productID', checkAuth, ProductsController.products_delete);


module.exports = router;