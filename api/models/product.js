const mongoose = require('mongoose');

//this is schema, (how the model is built)
const productSchema = mongoose.Schema({
    _id: mongoose.Schema.Types.ObjectId, 
    name: { type: String, required: true},
    price: { type: Number, required: true },
    productImage: { type: String, required: true }
})

module.exports = mongoose.model('Product', productSchema);