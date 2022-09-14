
const { db } = require("../firebase");
async function datosActuales(req, res){
    try {
        
        var ref = await db.ref("sensores/tempsMenMay");
        ref.once("value", function (snapshot) {
            console.log(snapshot.val());  
            const datos = snapshot.val(); 
            
           res.send(datos)

        });
      
       
    } catch (error) {
        console.log(error)

    }
}
async function datos(req, res){
    try {
        
        var ref = await db.ref("sensores/lastData");
        ref.once("value", function (snapshot) {
            console.log(snapshot.val());  
            const datos = snapshot.val(); 
            
           res.send(datos)

        });
      
       
    } catch (error) {
        console.log(error)

    }
}
function prueba(req, res) {
    res.render("prueba")
    
}

 function index(req, res) {
    res.render("index")
    
}
function updateDataTempMay(req, res) {
    console.log(req.body.mayor)
    var datos = Number(req.body.mayor);
    db.ref("sensores/tempsMenMay/Mayor").set(datos);
    res.redirect("/");
}
function updateDataTempMen(req, res) {
    console.log(req.body.menor)
    var datos = Number(req.body.menor);
    db.ref("sensores/tempsMenMay/Menor").set(datos);
    res.redirect("/");
}
function galeria(req, res){
    res.render('galeria')
}
module.exports = {
    index,
    updateDataTempMay,
    updateDataTempMen,
    datos,
    galeria,
    datosActuales,
    prueba,
}