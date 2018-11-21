//middleware for the system.
const dateTime = require('date-and-time');

module.exports = (req, res, next) => {
    try{
        let now = new Date();
        //console.log(dateTime.format(now, 'YYYY/MM/DD HH:mm:ss'));
        req.currentDateTime = dateTime.format(now, 'YYYY/MM/DD HH:mm:ss');
        next();
    } catch (error) {
        return res.status(401).json({
            message: 'Date failed'
        });
    }
    
};
