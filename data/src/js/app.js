
const app = new Vue({
    el:'#app',
    data:{
        titulo: 'Web Server esp8266',
        imagen_dia:'src/img/dia.jpeg',
        imagen_noche: 'src/img/noche.jpeg',
        estado: false,
        interrupor:{ // objeto interruptor
            state:'',
            pin:''
        },
    },
    methods:{
        /* FIXME: al llamar a la api arroja un error curl 
        algo asi como url cruzada 
        click:function(){
           axios.get('http://192.168.0.25/api/luz',{
               headers:{},
               mode: 'no-cors',
               withCredentials: true,
               credentials: 'same-origin',
           })
           .then((result)=>{
                console.log(result.data)
           })
        }
        */
    },
    /* TODO: el metodo estado debe hacer una solicitud patch y cambiar el estado del interruptor */
    watch:{
        estado(value){
            console.log(value)
        }
    }
});