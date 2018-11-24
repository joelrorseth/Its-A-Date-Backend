//location model
const mongoose = require('mongoose');

//date Schema
const locationSchema = mongoose.Schema({

    _id: mongoose.Schema.Types.ObjectId, 
    place_id: {type: String, required: true },
    name: { type: String, required: true },
    address: { type: String, required: true },
    rating: { type: String, required: true },
    dateCreated: {type: String, required: true },
    dateLastReferenced: {type: String, required: true }

})

module.exports = mongoose.model('Location', locationSchema);
