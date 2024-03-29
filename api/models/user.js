const mongoose = require('mongoose');

//user schema
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
    password: { type: String, required: true},
    userName: { type: String, required: true},
    bio: {type: String, required: false },
    phone: { type: String, required: false },
    nameFirst: { type: String, required: false },
    nameLast: { type: String, required: false },
    gender: { type: String, required: false },
    sexualOrientation: { type: String, required: false },
    relationshipStatus: { type: String, required: false },
    city: {type: String, required: false },
    age: { type: Number, required: false },
    dateCreated: { type: String, required: true },
    dateUpdated: { type: String, required: true },
    dateLastLogin: {type: String, required: true }

})

module.exports = mongoose.model('User', userSchema);