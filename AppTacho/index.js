const express = require('express');
const { engine } = require('express-handlebars');
const bodyParser = require('body-parser');


//Rutas

const index = require('./rutas/indexRutas');

const app = express();

var port =  3008;
app.set('port', port);
//Asignación de puerto
app.listen(app.get('port'), () => {
    //console.log("Corriendo en puerto" + app.get('port'));
    console.log("Corriendo en puerto: "+app.get('port'));
});

app.set('views', __dirname + '/vistas');
app.engine('.hbs', engine({
    extname: '.hbs',
    defaultLayout: 'main',
    layoutsDir: __dirname + '/vistas/layouts/'
}));
app.set('view engine', 'hbs');
//bodyparser sera usado para acceder a informacion del cuerpo de las peticiones
app.use(bodyParser.urlencoded({
    extended: true
}));
app.use(bodyParser.json());

//se asigna la ruta /static para poder hacer uso de archivos css,js, img, videos , etc.
app.use('/static', express.static('vistas/public'));


//Ruta login


app.use('/', index);