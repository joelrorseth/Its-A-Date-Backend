const mongoose = require('mongoose');

//this is schema, (how the model is built)
const dateSchema = mongoose.Schema({

    _id: mongoose.Schema.Types.ObjectId, 
    user: { type: mongoose.Schema.Types.ObjectId, ref: 'User', required: true },
    comments: { type: String, required: true },
    dateCreated: {type: String, required: true },
    dateUpdated: {type: String, required: true }

})

module.exports = mongoose.model('Date', dateSchema);