//dateLineEntry model
const mongoose = require('mongoose');

//date Schema
const dateLineEntrySchema = mongoose.Schema({

    _id: mongoose.Schema.Types.ObjectId, 
    date: { type: mongoose.Schema.Types.ObjectId, ref: 'Date', required: true },
    location: { type: mongoose.Schema.Types.ObjectId, ref: 'Location', required: true },
    name: { type: String, required: true },
    comments: { type: String, required: true },
    rating: { type: String, required: true },
    dateCreated: {type: String, required: true },
    dateUpdated: {type: String, required: true }

})

module.exports = mongoose.model('DateLineEntry', dateLineEntrySchema);