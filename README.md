# POO-entregas-FJ25
Repositorio para la entrega del proyecto - Programación orientada a objetos (Gpo 301)

# TC1030 Proyecto
<img src="https://github.com/DarioUribe-A01713776/POO-entregas-FJ25/blob/main/files/log.jpg"      alt="Logo Entre Abuelas" style="display: block; width: 100%; height: 40%;" />

# Gestión de inventario para Restaurantes
Actualmente, trabajo en un restaurante el cual necesita optimizar el control de su inventario. Al finalizar cada turno, el encargado de cocina registra manualmente el stock disponible, clasificándolo en cuatro secciones: Carnicería, Abarrotes, Verduras y Cremería. En cada categoría se anota la cantidad existente y la cantidad requerida de productos.

Para mejorar este proceso, se implementará una estructura basada en programación orientada a objetos, que permita gestionar de forma eficiente los productos, proveedores y pedidos.

## Funcionalidades
Registrar nuevos productos:
Permite dar de alta productos en el inventario especificando sus características como nombre, categoría, cantidad.

Eliminar productos:
Elimina productos del inventario cuando ya no están disponibles o han dejado de utilizarse.

Actualizar stock:
Modifica la cantidad existente de un producto tras recibir insumos o al finalizar un turno.

Mostrar inventario:
Muestra el listado completo de productos organizados por categoría (Carnicería, Abarrotes, Verduras y Cremería), junto con su cantidad disponible y cantidad requerida.

Agregar proveedores:
Permite registrar nuevos proveedores con su información de contacto, fecha de entrega y productos que suministran.

Eliminar proveedores:
Elimina del sistema a proveedores que ya no trabajan con el restaurante o que han sido reemplazados.

Reporte de proveedores:
Visualiza los datos de cada proveedor, incluyendo sus productos asignados y detalles de contacto.

Armar orden de pedido:
Permite crear órdenes de pedido seleccionando productos requeridos, asignando proveedor(es) y definiendo la fecha de solicitud.

Reporte de orden de pedido:
Muestra los detalles de una orden generada, incluyendo los productos solicitados, proveedor(es) involucrados y la fecha de pedido.

## Posibles casos en que el sistema podría dejar de funcionar

Entradas inválidas: Si el usuario introduce datos incorrectos (como cantidades negativas, nombres vacíos o fechas no válidas) y no hay validación, el programa puede comportarse de manera incorrecta o detenerse.

Eliminación de elementos relacionados: Si se elimina un proveedor o producto que está vinculado a una orden de pedido activa, y no se manejan bien esas relaciones, puede causar errores o pérdida de datos.

Falta de persistencia: Si los datos no se guardan correctamente (por ejemplo, en archivos o base de datos), toda la información se perderá al cerrar el programa.

Errores de actualización: Si al actualizar el stock se cometen errores lógicos (por ejemplo, no sumar correctamente la cantidad nueva), el inventario se desactualiza.

Sistema inflexible: Si el sistema no permite agregar nuevas categorías o tipos de productos sin modificar el código, será difícil escalar o adaptar el sistema a cambios reales en el restaurante.

## UML
![UML](https://github.com/DarioUribe-A01713776/POO-entregas-FJ25/blob/main/UML%20sistema%20inventario.png)

## Compilar y ejecutar:

Compilar: 

g++ -Iinclude sources/*.cpp -o inventario

Ejecutar:

.\inventario.exe

## Avances

Primer avance: Se desarrolló el diagrama UML que representa la estructura general del sistema. Se definieron las clases principales, sus atributos, métodos clave y relaciones.

Segundo avance: Se programó la clase Producto, la cual funciona como clase base del sistema de inventario, junto con sus respectivas clases derivadas: Carniceria, Abarrotes, Verdura y Cremeria. Estas implementan herencia y métodos de acceso para gestionar las características específicas de cada tipo de producto.
Además, se desarrolló la clase DiaCalendario, diseñada para manejar fechas relevantes en el sistema, como fechas de entrada y caducidad de productos, así como las fechas asociadas a proveedores y órdenes de pedido

Tercer avance: Se implementó el concepto de polimorfismo mediante la sobreescritura del método mostrarInfo() en las clases derivadas de Producto, permitiendo mostrar información específica según el tipo de producto.
Asimismo, se desarrollaron las clases Proveedor y OrdenPedido, que permiten gestionar los datos de contacto, fechas de entrega y productos suministrados por cada proveedor, así como la creación y manejo de órdenes de pedido con sus respectivas fechas, productos solicitados y proveedor asignado.

Cuarto avance: Se incorporaron nuevas clases, incluyendo reporte.h, reporteInventario.h, reporteInventario.cpp, con el objetivo de aplicar el concepto de clases abstractas y reforzar el diseño orientado a objetos del sistema.
Además, se implementó un archivo main funcional desde el cual es posible interactuar con el sistema mediante un menú que permite ejecutar diversas funcionalidades, como registrar productos, actualizar stock, agregar proveedores y generar órdenes de pedido.
Aunque el sistema ya realiza múltiples operaciones de manera efectiva, aún no se ha integrado la funcionalidad para visualizar reportes, y se encuentra en fase de mejora continua.

Ultimo avance: Puli todo el proyecto: revisamos y limpiamos los headers para quitar directivas duplicadas, corregimos la clase Proveedor agregándole el constructor y métodos para manejar sus productos, e implementamos las clases de reporte (ReporteInventario y ReporteOrdenPedido) como derivadas de la interfaz abstracta Reporte. Además añadimos en Inventario el método para buscar productos, lo que nos permitió ajustar el main.cpp para validar entradas, actualizar stock usando punteros y generar los reportes de inventario y pedidos en lugar de imprimirlo todo manualmente. Con esto ya funciona el flujo completo de registro, eliminación y visualización respetando las clases abstractas de reporte.