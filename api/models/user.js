const mongoose = require('mongoose');

//this is schema, (how the model is built)
const userSchema = mongoose.Schema({
    _id: mongoose.Schema.Types.ObjectId, 
    email: { 
        type: String, 
        required: true, 
        //unique: true,                     // this caused system to throw ensureIndex warning.
        match: /[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*@(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?/ 
    },       
    // you still need to check for multiple entries                         
    // unique helps with performance and search items.
    password: { type: String, required: true}
})

module.exports = mongoose.model('User', userSchema);