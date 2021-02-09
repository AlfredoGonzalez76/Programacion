%tarea

%del archivo 'base de autos sisko'

% 1) Abrir el archivo para lectura
% 2) Descartar las primeras 4 lineas usando fgetl
% 3) Usando fscanf leer los campos de alternativa usando estructuras
% 4) Plotear consumo en la ciudad respecto de la velocidad (mejor:consumo en ruta resp. de veloc)
% 5) obtener el maximo y minimo de cada uno de los campos
% 6) cerrar el archivo
% 7) Graficar los datos

clear;

fid = fopen('BaseAutosSiskos.txt' , 'r'); %la "r" indica lectura, ver help fopen

for i = 1 : 2
    aux = fgetl(fid); disp(aux); %imprime las 2 primeras filas vistas como string
end

n=10;

clc;

for i = 1:n
    
    fscanf(fid, '%s',1); %coloco esto 2 veces para que saltee "Alternativa"
    fscanf(fid, '%s',1);  %y el nro. de alternativa (pues estan separados x espacio)
    alternativa(i).marca = fscanf(fid, '%s', 1);
    alternativa(i).modelo = fscanf(fid, '%s', 1);
    alternativa(i).veloc = fscanf(fid, '%f', 1);
    alternativa(i).conscity = fscanf(fid,'%f', 1);
    alternativa(i).consruta = fscanf(fid, '%f', 1);
    alternativa(i).cv = fscanf(fid, '%f', 1);
    alternativa(i).espacio = fscanf(fid, '%f', 1);
    alternativa(i).precio = fscanf(fid, '%f', 1);
    fscanf(fid, '%s',1); %a este lo coloque p/q' saltee un campo q no interesa leer
    
end
aux = sprintf('--------------------------------------------------------------------'); disp(aux);

aux = sprintf('Hay %d alternativas de autos:',n); disp(aux);

for i = 1 : n
    aux = sprintf('%d )%s %s',i,alternativa(i).marca, alternativa(i).modelo); disp(aux);
end
aux = sprintf('--------------------------------------------------------------------'); disp(aux);

disp('¿Cual desea conocer?')

rta=0;
while (rta < 1) | (rta > 10)
    rta=input('');
end
alternativa(rta)

aux = sprintf('--------------------------------------------------------------------'); disp(aux);


disp('COMPARATIVAS:')
aux = sprintf('\n'); disp(aux);
disp('1) Velocidad.')
disp('2) Consumo en ciudad.')
disp('3) Consumo en ruta.')
disp('4) Potencia.')
disp('5) Espacio interior.')
disp('6) Precio.')
aux = sprintf('\n'); disp(aux);
disp('Ingrese el nro de la opcion que desea comparar:')

rta=10;
while (rta < 1) | (rta > 6)
    rta=input('');
end

switch rta
    
  case 1
    for k = 1 : n
        x(k)=alternativa(k).veloc;
    end
    bar(x); grid;
    ylabel('Velocidad')
    title('Grafico comparativo de Velocidades')
    [M,j]=max(x);
    aux = sprintf('\nEl auto de mayor velocidad es el %s  %s con %f km/h', alternativa(j).marca, alternativa(j).modelo,alternativa(j).veloc);
    disp(aux);
    [M,j]=min(x);
    aux = sprintf('y el de menor velocidad es el %s  %s con %f km/h.', alternativa(j).marca, alternativa(j).modelo,alternativa(j).veloc);
    disp(aux);
    p=mean(x);
    aux = sprintf('\nEl promedio de velocidad es de %f km/h.', p);
    disp(aux);

  case 2
    for k = 1 : n
        x(k)=alternativa(k).conscity;
    end
    bar(x); grid;
    ylabel('Consumo en ciudad')
    title('Grafico comparativo de Consumo en Ciudad')
    [M,j]=min(x);
    aux = sprintf('\nEl auto de menor consumo en ciudad es el %s  %s con %f l/km', alternativa(j).marca, alternativa(j).modelo,alternativa(j).conscity);
    disp(aux);
    [M,j]=max(x);
    aux = sprintf('y el de mayor consumo en ciudad es el %s  %s con %f l/km.', alternativa(j).marca, alternativa(j).modelo,alternativa(j).conscity);
    disp(aux);
    p=mean(x);
    aux = sprintf('\nEl consumo promedio es de %f l/km.', p);
    disp(aux);

  case 3
    for k = 1 : n
        x(k)=alternativa(k).consruta;
    end
    bar(x); grid;
    ylabel('Consumo en ruta')
    title('Grafico comparativo de Consumo en Ruta')
    [M,j]=min(x);
    aux = sprintf('\nEl auto de menor consumo en ruta es el %s  %s con %f l/km', alternativa(j).marca, alternativa(j).modelo,alternativa(j).consruta);
    disp(aux);
    [M,j]=max(x);
    aux = sprintf('y el de mayor consumo en ruta es el %s  %s con %f l/km.', alternativa(j).marca, alternativa(j).modelo,alternativa(j).conscity);
    disp(aux);
    p=mean(x);
    aux = sprintf('\nEl promedio de velocidad es de %f km/h.', p);
    disp(aux);
   
  case 4
    for k = 1 : n
        x(k)=alternativa(k).cv;
    end
    bar(x); grid;
    ylabel('Potencia')
    title('Grafico comparativo de Potencia')
    [M,j]=max(x);
    aux = sprintf('\nEl auto de mayor potencia es el %s  %s con %f CV', alternativa(j).marca, alternativa(j).modelo,alternativa(j).cv);
    disp(aux);
    [M,j]=min(x);
    aux = sprintf('y el de menor potencia es el %s  %s con %f CV.', alternativa(j).marca, alternativa(j).modelo,alternativa(j).veloc);
    disp(aux);
    p=mean(x);
    aux = sprintf('\nLa potencia promedio es de %f CV.', p);
    disp(aux);
   
  case 5
    for k = 1 : n
        x(k)=alternativa(k).espacio;
    end
    bar(x); grid;
    ylabel('Espacio Interior')
    title('Grafico comparativo de Espacio Interior')
    [M,j]=max(x);
    aux = sprintf('\nEl auto de mayor espacio interior es el %s  %s con %f dm3', alternativa(j).marca, alternativa(j).modelo,alternativa(j).espacio);
    disp(aux);
    [M,j]=min(x);
    aux = sprintf('y el de menor espacio interior es el %s  %s con %f dm3.', alternativa(j).marca, alternativa(j).modelo,alternativa(j).precio);
    disp(aux);
    p=mean(x);
    aux = sprintf('\nEl espacio interior promedio es de %f dm3.', p);
    disp(aux);
    
  case 6
    for k = 1 : n
        x(k)=alternativa(k).precio;
    end
    bar(x); grid;
    ylabel('Precio')
    title('Grafico comparativo de Precios')
    [M,j]=min(x);
    aux = sprintf('\nEl auto de menor precio es el %s  %s de $ %f', alternativa(j).marca, alternativa(j).modelo,alternativa(j).precio);
    disp(aux);
    [M,j]=max(x);
    aux = sprintf('y el de mayor precio es el %s  %s de $ %f.', alternativa(j).marca, alternativa(j).modelo,alternativa(j).conscity);
    disp(aux);
    p=mean(x);
    aux = sprintf('\nEl precio promedio es de $ %f.', p);
    disp(aux);
   
end
    xlabel('Los numeros corresponden a la lista de autos inicial');
    for k = 1 : n
        str1(1) = {alternativa(k).marca};
        str1(2) = {alternativa(k).modelo};
        set(text(k,1,str1),'Rotation',90,'Color','White');
    end
    
fclose(fid); %esto cierra el archivo Libro1.txt (esa es la sintaxis)
