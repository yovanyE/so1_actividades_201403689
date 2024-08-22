# Servicio de Saludo y Fecha Actual

## Instalación

1. **Crear un Script**

   - Crear el archivo del script en `/usr/local/bin/`:

     ```bash
     sudo nano /usr/local/bin/fechaSaludo.sh
     ```

   - Añadir el siguiente contenido al archivo:

     ```bash
     #!/bin/bash
     while true; do
       echo "Saudos, el día de hoy es: $(date)"
       sleep 1
     done
     ```

   - Darle permisos de ejecución al script:

     ```bash
     sudo chmod +x /usr/local/bin/fechaSaludo.sh
     ```

2. **Crear el Archivo de Unidad de Systemd**

   - Crear el archivo de unidad en `/etc/systemd/system/`:

     ```bash
     sudo nano /etc/systemd/system/fechaSaludo.service
     ```

   - Añadir el siguiente contenido al archivo:

     ```ini
     [Unit]
     Description=Servicio para imprimir saludo y fecha actual

     [Service]
     ExecStart=/usr/local/bin/fechaSaludo.sh
     Restart=always
     User=nobody

     [Install]
     WantedBy=multi-user.target
     ```

3. **Habilitar e Iniciar el Servicio**

   - Recarga el daemon de `systemd`:

     ```bash
     sudo systemctl daemon-reload
     ```

   - Habilitar el servicio:

     ```bash
     sudo systemctl enable fechaSaludo.service
     ```

   - Iniciar el servicio:

     ```bash
     sudo systemctl start fechaSaludo.service
     ```

   - Verificar el estado del servicio:

     ```bash
     sudo systemctl status fechaSaludo.service
     ```

## Comprobación de Logs

para los logs del servicio podemos ver usando el comando `journalctl`:

```bash
sudo journalctl -u fechaSaludo.service
