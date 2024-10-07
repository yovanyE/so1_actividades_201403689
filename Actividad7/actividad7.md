# Actividad 7 - Describir las características principales y el funcionamiento del Completely Fair Scheduler (CFS) de Linux.

## El Completely Fair Scheduler (CFS) es el planificador de procesos utilizado en el núcleo de Linux desde la versión 2.6.23. Su principal objetivo es proporcionar una distribución justa del tiempo de CPU entre todos los procesos maximizando la eficiencia y minimizando la latencia. 
# Características Principales:

- Justicia en la Asignación de Tiempo: CFS asegura que cada proceso obtenga su parte justa del tiempo de CPU. Esto significa que, a largo plazo, todos los procesos deben recibir una cantidad equitativa de tiempo de CPU.

- Uso de un Árbol Rojo-Negro: CFS utiliza una estructura de datos llamada árbol rojo-negro (un tipo de árbol binario auto-equilibrado) para gestionar los procesos en la cola de espera. Esto permite una inserción, eliminación y búsqueda eficientes de procesos.

- Uso de la Tarea Virtual (vruntime): Cada proceso tiene un valor de vruntime, que representa el tiempo que ha estado ejecutándose. Cuanto menor es el vruntime, mayor es la prioridad del proceso. CFS selecciona el proceso con el menor vruntime para ejecutarlo.

- Desviación de la Latencia: CFS permite que la latencia para procesos interactivos se reduzca, haciendo que estos tengan un vruntime que aumenta más lentamente cuando están inactivos.

- No Preemptivo por Defecto: CFS permite que los procesos se ejecuten hasta que terminen su "quantum" o tiempo asignado, aunque también puede ser interrumpido por procesos de mayor prioridad.

- Configuración de Prioridades: CFS permite a los usuarios y administradores ajustar las prioridades de los procesos a través de diferentes niveles de prioridad, lo que puede influir en cómo se asigna el tiempo de CPU.

# Funcionamiento:
- Enqueue (Colocación): Cuando un proceso se inicia o se vuelve a activar, se agrega a la cola del CFS y se le asigna un vruntime inicial.

- Scheduling (Planificación): CFS selecciona el proceso con el menor vruntime para ejecutarse. Si un nuevo proceso se une a la cola y tiene un vruntime menor que el del proceso que está ejecutándose, el CFS puede interrumpir el proceso actual y ejecutar el nuevo.

- Dequeue (Extracción): Cuando un proceso termina su ejecución o se bloquea, su vruntime se utiliza para determinar su posición en la cola para la próxima vez que se planifique.

- Balanceo de Carga: CFS puede adaptarse a la carga del sistema. Si hay muchos procesos en ejecución, la cantidad de tiempo que cada proceso recibe se ajusta automáticamente.

- Ajuste de vruntime: Durante la ejecución, el vruntime del proceso en ejecución aumenta en función de su tiempo de CPU consumido, lo que permite a CFS mantener un control justo sobre la ejecución de todos los procesos.

El CFS ha sido diseñado para equilibrar la carga del sistema y proporcionar una experiencia fluida y responsiva para los usuarios, siendo particularmente efectivo en sistemas multitarea.