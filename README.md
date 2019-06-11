1) Escribir un fichero con el formato
Nombre_Del_Modelo Min Max
Ecuacion1
Ecuacion2
.
.
.
EcuacionN

2) Ejecutar python file_parser.py nombre_del_fichero

3) Copiar la carpeta generada en model_library/neuron con el nombre del modelo al directorio también llamado model_library/neuron en nm_dt_pts_calculator

4) Ejecutar python calculator.py Nombre_Del_Modelo

5) Descomentar la línea con nm->set_pts_burst = &nm_komendantov_kononenko_1996_set_pts_burst; en nm_komendantov_kononenko_1996.c

6) Comprobar que todos los pasos de integración seleccionados son correctos, al menos los de los extremos, usando python test.py Nombre_Del_Modelo Id_Metodo_Integracion Paso_Integracion