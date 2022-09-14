const express = require('express');
const indexController = require('../controllador/indexController');
const router = express.Router();




router.get('/',  indexController.index);
router.get('/prueba',  indexController.prueba);

router.get('/datos',  indexController.datos);
router.get('/galeria', indexController.galeria);
router.post('/temMay',  indexController.updateDataTempMay);
router.post('/temMen',  indexController.updateDataTempMen);

router.get('/datosMinMay',  indexController.datosActuales);




module.exports = router;