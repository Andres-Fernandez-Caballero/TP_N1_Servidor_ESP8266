const divEstado = document.getElementById('divEstado');

function actualizarEstado(estado){
    divEstado.innerHTML = estado? 'Encendida' : 'Apagada';
}

const conexion = new WebSocket('ws://192.168.0.25/estado_luz');

conexion.onopen = function(){
    console.log("conectado al socket");
}

conexion.onerror = function(){
    console.log('error de conexion al socket');
}

conexion.onmessage = function(e){
    actualizarEstado(e.data);
    console.log('data from server \n estado = ', e);
}

conexion.onclose = function(){
    console.log('conexion del socket cerrada');
}