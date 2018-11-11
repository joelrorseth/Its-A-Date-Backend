const express = require('express');         // router task library
const app = express();                      // router task/redirection http helpers
const morgan = require('morgan');           // logs in terminal via next in calls to router etc...
const bodyParser = require('body-parser');  // allows you to parse incoming requests and urls or json data
                                            // doesn't support files
const mongoose = require('mongoose');       // use mongoose for working with mongoDB


/*
    CORS- Cross Origin Resource sharing
    Client <=> Server (if on same server)
    then localhost&port etc will be the same. traditional pages where html pages on same server it will find them ok.
    For RESTful API this is never the case.
    Client <=> Server (always different, or almost always)
    then localhost&port likely different. making request to a server resource will fail because browser will block access.
    We disable this mechanism by sending headers to browser. 
*/

const productRoutes = require('./api/routes/products');
const orderRoutes = require('./api/routes/orders');
const userRoutes = require('./api/routes/user');

mongoose.connect(
    'mongodb://shop-test:' + 
    process.env.MONGO_ATLAS_PW + 
    '@shoptest-shard-00-00-xcuuh.mongodb.net:27017,shoptest-shard-00-01-xcuuh.mongodb.net:27017,shoptest-shard-00-02-xcuuh.mongodb.net:27017/test?ssl=true&replicaSet=shoptest-shard-0&authSource=admin&retryWrites=true',
{            
    useNewUrlParser: true                //this 2nd arg tells to use MongoDB to connect (new parameter from video, previous was deprecated.)
})

// this clears the warning in video
// mongoose.Promise = global.Promise;

// accepts all requests to the general folder or any folder. 
// app.use((req, res, next) => {
//     res.status(200).json({
//         message: 'It works!'
//     });
// });

// use to log in terminal using the "next" param of the router.get(or post) calls
app.use(morgan("dev"));
app.use('/uploads',express.static('uploads'));       //use to make upload folder publically available. first arg ignore that path element
// this needs to have an extra parser so it can read form data for when doing tokens.
/* this is a hard bug to find, watch for this. */
app.use(bodyParser.urlencoded({extended: false}));   // true allows extended bodies with rich data
app.use(bodyParser.json());

// stopped working review this section. 
app.use((req, res, next) => {
    res.header("Access-Control-Allow-Origin", "*"); // could restrict by changing * to a url or something.
    res.header("Access-Control-Allow-Headers", 
        "Origin, X-Requested-With, Content-Type, Accept, Authorization");
    //initial request by browser to see if able to make requests.
    // set up so it allows this to 
    if (req.method === 'OPTIONS'){
        res.header('Access-Control-Allow-Methods', ' PUT, POST, PATCH, DELETE, GET');
        return res.status(200).json({});
    }
    next();
 });

// routes that handle requests
app.use('/products', productRoutes);
app.use('/orders', orderRoutes);
app.use('/user', userRoutes);

// set up error handling, don't use first param so it catches everything.
app.use((req, res, next) => {
    const error = new Error('Not Found');
    error.status = 404;
    next(error);
});

// adding this here will allow us to catch errors from anywhere in the application. (like in DB)
app.use((error, req, res, next) => {
    res.status(error.status || 500);
    res.json({
        error: {
            message: error.message
        }
    });
});


module.exports = app;