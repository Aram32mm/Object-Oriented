#include <iostream>
#include <string.h>
#include "cliente.h"
#include "producto.h"
#include "categoria.h"


using namespace std;

//Las pymes agrupan a las pequeñas y medianas empresas y son fundamentales. 
//En el caso de México se estima que son responsables del 72% de los empleos.
//El COVID-19 afectó a este tipo de negocios más que a ningún otro.
//La pandemia aceleró el comercio electrónico y pagos sin contacto en todo el mundo.
//Por esta razón, este proyecto busca ayudar a pymes con un código que permita
//al usuario contar con una base de datos de productos y clientes con la habilidad 
//de que se generen pedidos.


int main(){


    //El dueño ingresa los productos en existencia
    Producto p11(11,"Cacao en Polvo Orgánico               ","Xoco Maya                         ",119.00);
    Producto p12(12,"Levadura Nutricional                  ","Bob's Red Mill                    ",279.00);
    Producto p13(13,"Aceite de Coco Neutro                 ","NB FOODS                          ",152.50);
    Producto p14(14,"Harina de Almendra                    ","Morama                            ",189.00);
    Producto p15(15,"Chocolate Amargo                      ","Culto                             ",99.00);

    Producto p21(21,"Agua Gasificada                       ","La Cocina Verde                   ",26.00);
    Producto p22(22,"Agua de Coco Orgánica                 ","Acapulcoco                        ",17.00);
    Producto p23(23,"Jugo de Naranja                       ","Campo Vivo                        ",71.00);
    Producto p24(24,"Leche de Avena con Almendra           ","Real Natural                      ",79.00);
    Producto p25(25,"Té Kombucha Original                  ","La Semilla Colectivo              ",95.50);

    Producto p31(31,"Perfume Natural UNISEX                ","Perfumérica                       ",617.00);
    Producto p32(32,"Pasta Dental Antiséptica              ","Manantial de Las Flores           ",98.50);
    Producto p33(33,"Jabón en Algas Marinas                ","García                            ",27.00);
    Producto p34(34,"Shampoo de Romero en Barra            ","Manantial de Las Flores           ",80.50);
    Producto p35(35,"Gotas de Miel para Ojos               ","Bio meliponum                     ",112.50);

    Producto p41(41,"Detergente Enzimático de Hierbabuena  ","Elet                              ",236.00);
    Producto p42(42,"Desinfectante en Spray                ","Citrof B                          ",54.00);
    Producto p43(43,"Lavaplatos Líquido Neutro sin Sulfatos","Elet                              ",89.00);
    Producto p44(44,"Tamalitos de pollo para perro         ","Tamalitos Dog                     ",146.50);
    Producto p45(45,"Servilletas Ecológicas                ","Velty                             ",36.00);
    

    //Se agregran a su categoria
    Categoria c1(1,"Despensa");
    c1.agregarProducto(p11, 0);
    c1.agregarProducto(p12, 1);
    c1.agregarProducto(p13, 2);
    c1.agregarProducto(p14, 3);
    c1.agregarProducto(p15, 4);

    Categoria c2(2,"Bebidas");
    c2.agregarProducto(p21, 0);
    c2.agregarProducto(p22, 1);
    c2.agregarProducto(p23, 2);
    c2.agregarProducto(p24, 3);
    c2.agregarProducto(p25, 4);

    Categoria c3(3,"Higiene Personal y Belleza");
    c3.agregarProducto(p31, 0);
    c3.agregarProducto(p32, 1);
    c3.agregarProducto(p33, 2);
    c3.agregarProducto(p34, 3);
    c3.agregarProducto(p35, 4);

    Categoria c4(4,"Hogar, Mascota y Accesorios");
    c4.agregarProducto(p41, 0);
    c4.agregarProducto(p42, 1);
    c4.agregarProducto(p43, 2);
    c4.agregarProducto(p44, 3);
    c4.agregarProducto(p45, 4);


    //Interfaz de Entrada
    Cliente clint1;
    cout<<"Bienvenido a 'La Esquina Verde', tienda en línea"<<endl;
    cout<<"Produtos 100% naturales y orgánicos"<<endl;
    cout<<"Antes de continuar comprando, ingrese sus datos y registrese en el sistema"<<endl;
    string nombre;
    string correo;
    string contra;
    cout<<"Nombre: "; cin>>nombre; clint1.setNombreUsuario(nombre);
    cout<<"Correo Electrónico: "; cin>>correo; clint1.setCorreo(correo);
    cout<<"Contraseña: "; cin>>contra; clint1.setContra(contra);
    cout<<"Estás Registrado! "<<endl;;
    cin.ignore();
    cout<<"Además, La Esquina Verde recomienda a sus usuarios maximizar la terminal para una mejor experiencia :)"<<endl;
    cout<<"Press [Enter] para ver Menú"<<endl;
    cin.get();


    //Código para menú de opciones

    int opcion; //Para switch 

    int r = 1; string respuesta = ""; //Para do-while 
   

        do{
            cout<<"\t\t.:La Esquina Verde Menú:.";
            c1.imprimirCategoria();
            c2.imprimirCategoria();
            c3.imprimirCategoria();
            c4.imprimirCategoria();
            cout<<"\nQue quieres hacer? "<<endl;
            cout<<"> Agregar productos a mi carrito     [1]"<<endl;
            cout<<"> Ver mi carrito                     [2]"<<endl;
            cout<<"> Pagar                              [3]"<<endl;
            cout<<"> Salir                              [4]\n"<<endl;


            cout<<"Seleccione el código de la opción que desea realizar: "; cin>>opcion;
                switch(opcion)
                {
                    case 1: 
                            int c;
                            cout<<"Tecleé el código del producto que quisiera agregar: "; cin>>c;
                                if((c>=10) && (c<=15)){
                                    int cN;
                                    cN = c - 11;
                                    c1.agregarCarrito(cN);
                                    cout<<"Agregado."<<endl;
                                   

                                }else if((c>=20) && (c<=25)){
                                    int cN;
                                    cN = c - 21;
                                    c2.agregarCarrito(cN);
                                    cout<<"Agregado."<<endl;
                                    

                                }else if((c>=30) && (c<=35)){
                                    int cN;
                                    cN = c - 31;
                                    c3.agregarCarrito(cN);
                                    cout<<"Agregado."<<endl;
                                    

                                }else if((c>=40) && (c<=45)){ 
                                    int cN;
                                    cN = c - 41;
                                    c4.agregarCarrito(cN);
                                    cout<<"Agregado."<<endl;
                                    

                                }else{
                                    cout<<"Código No Existente."<<endl;
                                }
                            continue;



                    case 2 :
                            cout<<"Mi carrito: "<<endl;
                            c1.imprimirCarrito();
                            c2.imprimirCarrito();
                            c3.imprimirCarrito();
                            c4.imprimirCarrito(); 

                            cout<<"Presiona [C/c] para continuar comprando!"<<endl;
                            cout<<"Presiona [P/p] para pagar.   R= ";cin>>respuesta;cout<<"\n";
                            if((respuesta == "P") || (respuesta == "p")){
                            }else if((respuesta == "C") || (respuesta == "c")){
                                break;
                            }else{
                                cout<<"Opción No Existente.\n"<<endl;
                                break;
                            }





                    case 3 :
                            double total;
                            int tarjeta;
                            int cvv;
                            total = c1.calcularPreciofinal() + c2.calcularPreciofinal() + c3.calcularPreciofinal()+ c4.calcularPreciofinal(); 
                            cout<<"Total $"<<total<<" pesos"<<endl;
                            

                            cout<<"Presiona [C/c] para realizar el check-out!"<<endl;
                            cout<<"Presiona [V/v] por si quieres volver.    R= ";cin>>respuesta; cout<<"\n";

                            if((respuesta == "C") || (respuesta == "c")){
                                int cvv;
                                cout<<"Ingrese el código de seguridad de su trajeta de crédito para finalizar con su compra."<<endl;;
                                cout<<"CVV :"; 
                                cin>>cvv; 

                                clint1.pago(cvv);
                                
                                cout<<"Tu compra a sido finalizada con éxito "<<nombre<<"."<<endl;
                                cout<<"Productos comprados: "<<endl;
                                c1.imprimirCarrito();
                                c2.imprimirCarrito();
                                c3.imprimirCarrito();
                                c4.imprimirCarrito();
                                
                                r -=1;
                                break;
                                


                        
                            }else if((respuesta == "V") || (respuesta == "v")){
                            break;
                            }else{
                            cout<<"Código No Existente.\n"<<endl;
                            break;
                            }
                      




                    case 4 :
                            r -=1;
                            break;




                    default:   
                            cout<<"Opción Inválida"<<endl;    
                            break;
        
                }

            
        }while (r==1);


    return 0;
}