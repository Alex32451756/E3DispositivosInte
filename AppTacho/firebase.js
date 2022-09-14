const firebase = require('firebase-admin')

var serviceAccount = require("./espprueba32-firebase-adminsdk-2tp9l-82128bcbbe.json");


firebase.initializeApp({
    credential: firebase.credential.cert(serviceAccount),
    databaseURL: 'https://espprueba32-default-rtdb.firebaseio.com/'
});

const db = firebase.database();
module.exports = {
    db,
  };