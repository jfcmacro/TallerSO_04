# Taller 4

## Agenda

1. Preliminares
2. Creación de procesos
   1. Linux
   2. Windows
3. Creación de hilos
   1. Linux
   2. Windows

## Preliminares

Abra una terminal. Abra el directorio de repositorio y de los talleres

```
cd <repositorio-enlace>
cd talleres
```

Descargue el taller en formato zip, descomprimalo.

```
wget https://github.com/jfcmacro/TallerSO_04/archive/refs/heads/master.zip
unzip master.zip
rm master.zip
```

Mire la estructura actual

```
tree .
```

Entre al directorio del taller

```
cd TallerSO_04-master
```

Adicione los ficheros

```bash
git add README.md .gitignore
```

Adicione los ficheros del proyecto, esto adiciona todos ficheros del taller.

```bash
find . -name *.c -exec git add {} \;
find . -name .keep -exec git add {} \;
find . -name makefile -exec git add {} \;
find . -name *.txt -exec git add {} \;
find . -name *.cmd -exec git add {} \;
```

Acometa (*commit*) el proyecto.

```
git commit -m "Iniciando el Taller 04"
git push
```

## Creación de procesos

### Creación de procesos en Linux

[Creación de procesos en Linux](./crear-procesos/linux/)

### Creación de procesos en Windows

[Creación de procesos en Windows](./crear-procesos/windows/)

## Creación de hilos

### Creación de hilos en Linux

[Creación de hilos en Linux](./crear-hilos/linux/)

### Creación de hilos en Windows

[Creación de hilos en Windows](./crear-hilos/windows/)