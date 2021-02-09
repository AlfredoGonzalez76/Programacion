!  Vieira.f90 
!
!  FUNCTIONS:
!  VieiraPrg - Entry point of console application.
!

!****************************************************************************
!
!  PROGRAM: VieiraPrg
!
!  PURPOSE:   MODELO DE DINAMICA POBLACIONAL PARA VIEIRA PATAGONICA
!
!****************************************************************************

      program Vieira

      implicit none

      character*60 ardat1,ardat2,arsal,arshow1,arshow2
      character*80 texto1,texto2,encab
      real*8 X1(100,150),X2(100,150),marcas(100),G0a(150),G11a(150),G12a(150),G13a(150),G21a(150),G22a(150)
      real*8 G0b(150),G11b(150),G12b(150),G13b(150),G21b(150),G22b(150),GR1a(150),GR2a(150),GR1b(150),GR2b(150)
      real*8 l0,l11,l12,l13,l21,l22,N01,N11,N21,N02,N12,N22
      real*8 abmin1,abmax1,areat1,abmin2,abmax2,areat2,aux,CONT,Nmin
      real*8 nn1(150),nn2(150),ab1(150),ab2(150),PCL1(150),PCM1(150),PCL2(150),PCM2(150)
      real*8 X1SIM(100,150),X2SIM(100,150),FR1(100,150),FR2(100,150),FRA1(100,150),FRA2(100,150)
      integer nl1, nl2, nclas1, nclas2, med, ind, t
      integer, parameter :: NSIM = 1000
      real *8 p_t(NSIM),p0t(NSIM),p1t(NSIM),p2t(NSIM),N0t(NSIM),N1t(NSIM),N2t(NSIM),N0t1(NSIM),N1t1(NSIM),N2t1(NSIM)
      
      write(*,'(60/)')
      write(*,20)
20    format(2x,'PRG: SHELLDYN v310317 GMAT-GECOMAT',/)

      write(*,30)
30    format(2x,'archivo de datos 1: ',$)
      read(*,'(60a)') ardat1
      
      write(*,35)
35    format(2x,'archivo de datos 2: ',$)
      read(*,'(60a)') ardat2
      
      write(*,'(//)')
      write(*,40)
40    format(2x,'archivo de resultados: ',$)
      read(*,'(60a)') arsal
      
!      write(*,'(//)')
!      write(*,55)
!55    format(2x,'archivo de muestra 1: ',$)
!      read(*,'(60a)') arshow1
!
!      write(*,'(//)')
!      write(*,65)
!65    format(2x,'archivo de muestra 2: ',$)
!      read(*,'(60a)') arshow2

!
! NOTA: DATOS DE MUESTRAS DE LANCE DE PESCA
!      
      call LeeArch(ardat1,texto1,encab,nclas1,nl1,abmin1,abmax1,areat1,marcas,X1,PCL1,PCM1,l0,l11,l12,l13,l21,l22)
      call LeeArch(ardat2,texto2,encab,nclas2,nl2,abmin2,abmax2,areat2,marcas,X2,PCL2,PCM2,l0,l11,l12,l13,l21,l22)
      
!
! Muestra la matriz X original
!
!     call Muestra(nl1,nclas1,X1,arshow1)

!
! Se calcula el nº de individuos muestreados por lance de pesca
!
      call Totales(nl1, nclas1, nn1, X1)
      call Totales(nl2, nclas2, nn2, X2)

! Selecciona los lances cuyo nº de individuos es mayor o igual a Nmin
!
      Nmin = 200
      call Select(nl1, nclas1, nn1, X1, Nmin)
      call Select(nl2, nclas2, nn2, X2, Nmin)

!
! Muestra la matriz X luego de quitar los lances cuyo nº de individuos es menor a Nmin
!
!     call Muestra(nl1,nclas1,X1,arshow2)

! Expande la muestra de cada lance al respectivo lance
!
      call Expande(nl1, nclas1, nn1, X1, PCL1, PCM1)
      call Expande(nl2, nclas2, nn2, X2, PCL2, PCM2)

! Se calcula el nº total de individuos por lance de pesca
!
      call Totales(nl1, nclas1, nn1, X1)
      call Totales(nl2, nclas2, nn2, X2)
      
! se generan las tablas de frecuencias relativas de longitudes
!
      call FrecRel(nl1,nclas1,nn1,X1,FR1)
      call FrecRel(nl2,nclas2,nn2,X2,FR2)
      
! se generan las tablas de frecuencias relativas acumuladas
      
      call FrecRelAc(nl1,nclas1,FR1,FRA1)
      call FrecRelAc(nl2,nclas2,FR2,FRA2)

      t = 0
      CONT = 0
      open(30,file=arsal)
      write(30,'(80a)') texto1
      write(30,'(80a)') texto2
      write(30,45)
45    format(1x,'N01',15x,'N11',15x,'N21',15x,'N02',15x,'N12',15x,'N22',19x,'p_t',5x,'p0t',5x,'p1t',5x,'p2t')
      do while ((CONT <= NSIM).or.(t<=10*NSIM))
         t = t + 1
         call SimTabla(nl1,nclas1,nn1,X1SIM,FRA1,abmin1,abmax1,areat1)
         call SimTabla(nl2,nclas2,nn2,X2SIM,FRA2,abmin2,abmax2,areat2)
! 
!        Se contabiliza el nº de individuos en cada grupo: G0, G11, G12, G13, G21, G22
!        N0=G0; N1=G11+G12+G13; N2=G21+G22
!
         call Grupos(nl1, marcas, l0, l11, l12, l13, l21, l22, X1SIM, G0a, G11a, G12a, G13a, G21a, G22a, GR1a, GR2a)
         call Grupos(nl2, marcas, l0, l11, l12, l13, l21, l22, X2SIM, G0b, G11b, G12b, G13b, G21b, G22b, GR1b, GR2b)
         
         N01=Mediana(nl1,G0a)
         N11=Mediana(nl1,GR1a)
         N21=Mediana(nl1,GR2a)
      
         N02=Mediana(nl2,G0b)
         N12=Mediana(nl2,GR1b)
         N22=Mediana(nl2,GR2b)

         if (((Mediana(nl2,G11b)/Mediana(nl1,G0a)).lt.1).and.((Mediana(nl2,G21b)/Mediana(nl1,G13a)).lt.1)) then
            CONT=CONT+1
            p_t = Mediana(nl1,G13a)/N11
            p0t = Mediana(nl2,G11b)/Mediana(nl1,G0a)
            p1t = Mediana(nl2,G21b)/Mediana(nl1,G13a)
            p2t = (N22-Mediana(nl2,G21b))/N21
            
            N0t = N01
            N1t = N11
            N2t = N21
            
            N0t1 = N02
            N1t1 = N12
            N2t1 = N22
            
            write(30,50) N01,N11,N21,N02,N12,N22,p_t,p0t,p1t,p2t
50          format(1x,6(f12.0,1x),4x,4(f8.6,1x))
         endif
      enddo
      write(*,*) 'Número Total de Simulaciones: ',t
      
      
!**********************************************************************
! SUBRUTINAS:
!**********************************************************************
      contains
      
!**********************************************************************
!LeeArch: lee la información de los archivos de entrada
!**********************************************************************
     subroutine LeeArch(ardat,texto,encab,nclas,nl,abmin,abmax,areat,marcas,X,PCL,PCM,l0,l11,l12,l13,l21,l22)
      character*60 ardat
      character*80 texto,encab
      integer nclas, nl, i, j
      real*8 abmin,abmax,areat, X(100,150), marcas(100),l0,l11,l12,l13,l21,l22
      real*8 PCL(150),PCM(150)              ! Peso de la Captura en el lance y Peso de la captura en la Muestra.
        open(30,file=ardat)
        read(30,'(80a)') texto              ! lee la primera línea del archivo: Descripción del contenido del archivo
        read(30,'(80a)') encab              ! lee los encabezados de los valores por venir
        read(30,*) nclas,nl                 ! nclas: numero de clases de longitudes    nl: numero de lances
        read(30,'(80a)') encab              ! lee los encabezados de los valores por venir
        read(30,*) (PCL(j),j=1,nl)          ! lee el Peso de la Captura de vieira por Lance
        read(30,'(80a)') encab              ! lee los encabezados de los valores por venir
        read(30,*) (PCM(j),j=1,nl)          ! lee el Peso de la Captura de vieira en la Muestra (mayores+menores)
        read(30,'(80a)') encab              ! lee los encabezados de los valores por venir
        do i=1,nclas
           read(30,*) marcas(i),(X(i,j),j=1,nl)
        enddo
        read(30,'(80a)') encab              ! lee la línea que informa las longitudes en que se separa un grupo de otro
        read(30,*) l0,l11,l12,l13,l21,l22
        read(30,'(80a)') encab              ! encabezado de área barrida mínima y máxima de los lances
        read(30,*) abmin,abmax
        read(30,'(80a)') encab              ! encabezado previo a dar el área total del banco 1
        read(30,*) areat
        close(30)
      end subroutine LeeArch

!**********************************************************************
! Totales: calcula los totales de nº de individuos
!**********************************************************************
! Peso de Vieira en la muestra = Peso mayores muestra + Peso menores muestra
! Peso de Vieira en el lance = Captura de Vieira en el lance
      
      subroutine Totales(nl,nclas,nn,X)
      integer i, j, nl, nclas
      real*8 nn(150), X(100,150) 
        do j=1,nl    
           nn(j)=0.d0
        enddo
        do j=1,nl
           do i=1,nclas
              nn(j)=nn(j)+X(i,j)
           enddo 
        enddo
      end subroutine Totales
      
!****************************************************************************
! Select: Selecciona los lances cuyo nº de individuos es mayor o igual a Nmin
!****************************************************************************
      subroutine Select(nl,nclas,nn,X,Nmin)
      integer h, i, j, nl, nclas
      real*8 nn(150), X(100,150), Nmin
         j=1
         do while((nl-j) >= 0) 
            if (nn(j)<Nmin) then
               do h=j,nl-1
                  do i=1,nclas
                      X(i,h)=X(i,h+1)
                  enddo
                  nn(h)=nn(h+1)
               enddo
               nl=nl-1
            else
               j=j+1
            endif
         enddo
      end subroutine Select
      
!*********************************************************************************
! Muestra: ! Muestra cómo queda la matriz X
!*********************************************************************************
      subroutine Muestra(nl,nclas,X,arshow)
      character*60 arshow
      integer i, j, nl, nclas
      real*8 X(100,150)
      open(50,file=arshow)
      do i=1, nclas
         do j=1,nl
            write(50,*) X(i,j)
         enddo
      enddo
      end subroutine Muestra

!*********************************************************************************
! Expande: ! Expande el nº de individuos muestreados al nº de individuos del lance
!*********************************************************************************
      subroutine Expande(nl,nclas,nn,X,PCL,PCM)
      integer i, j, nl, nclas
      real*8 nn(150), X(100,150), PCL(150), PCM(150) 
         do i=1,nclas
           do j=1,nl
              X(i,j)=X(i,j)*(PCL(j)/PCM(j))
           enddo
        enddo
      end subroutine Expande
    
!**********************************************************************
! FrecRel: calcula las frecuencias relativas de las tablas dadas
!**********************************************************************
      subroutine FrecRel(nl,nclas,nn,X,FR)
      integer i, j, nl, nclas
      real*8 nn(150),X(100,150),FR(100,150)
      do j=1,nl
         do i=1,nclas
            FR(i,j)=X(i,j)/nn(j)
         enddo
      enddo
      end subroutine FrecRel

!**********************************************************************
! FrecRelAc: calcula las frecuencias relativas acumuladas de las tablas
!**********************************************************************
      subroutine FrecRelAc(nl,nclas,FR,FRA)
      integer i, j, nl, nclas
      real*8 FR(100,150),FRA(100,150)
      do j=1,nl
         FRA(1,j)=FR(1,j)
         do i=2,nclas
            FRA(i,j)=FRA(i-1,j)+FR(i,j)
         enddo
      enddo
      end subroutine FrecRelAc

!**********************************************************************
! LISTO PARA COMENZAR LAS SIMULACIONES
!**********************************************************************  
! SimTabla: SIMULACION DE MONTE CARLO SE GENERAN TABLAS X1SIM Y X2SIM
! a nivel poblacional (N por clase de longitud poblacional)
!**********************************************************************
      subroutine SimTabla(nl,nclas,nn,XSIM,FRA,abmin,abmax,areat)
      integer i, j, k, nl, nclas
      real*8 nn(150),XSIM(100,150),FRA(100,150), ab(150), abmin, abmax, areat, u
      do i=1,nclas
         do j=1,nl
            XSIM(i,j)=0.d0
         enddo
      enddo
      do j=1,nl
         do k=1,nn(j)
            call random_number(u)
            if (u .le. FRA(1,j)) then
               XSIM(1,j)=XSIM(1,j)+1.d0
            else
               i=2
               do while(.not.((FRA(i-1,j).lt.u).and.(u.le.FRA(i,j))))
                  i=i+1
               enddo
               XSIM(i,j)=XSIM(i,j)+1.d0
            endif
         enddo
! SE GENERA UN FACTOR DE EXPANSION POR LANCE AL NIVEL POBLACIONAL
         call RANDOM_NUMBER(u)
         ab(j)=abmin+u*(abmax-abmin)
         do i=1,nclas
            XSIM(i,j)=areat*XSIM(i,j)/ab(j)
         enddo
      enddo
      end subroutine SimTabla

!**********************************************************************
! Grupos: Calcula el nº de individuos en cada grupo
!**********************************************************************
      subroutine Grupos(nl, marcas, l0, l11, l12, l13, l21, l22, XSIM, G0, G11, G12, G13, G21, G22, GR1, GR2)
      real*8 XSIM(100,150),G0(150),G11(150),G12(150),G13(150),G21(150),G22(150),GR1(150),GR2(150),marcas(100)
      real*8 l0,l11,l12,l13,l21,l22,N0,N1,N2
      integer i,j,nl
      do j=1,nl
         G0(j)=0.d0
         G11(j)=0.d0
         G12(j)=0.d0
         G13(j)=0.d0
         G21(j)=0.d0
         G22(j)=0.d0
         i=1
         do while(marcas(i).lt.l0)
            i=i+1
         enddo
         do while((l0.le.marcas(i)).and.(marcas(i).lt.l11))
            G0(j)=G0(j)+XSIM(i,j)             ! Estimación del nº total de individuos del grupo G0 hecha desde el lance j
            i=i+1
         enddo
         do while((l11.le.marcas(i)).and.(marcas(i).lt.l12))
            G11(j)=G11(j)+XSIM(i,j)           ! Estimación del nº total de individuos del grupo G11 hecha desde el lance j
            i=i+1
         enddo
         do while((l12.le.marcas(i)).and.(marcas(i).lt.l13))
            G12(j)=G12(j)+XSIM(i,j)           ! Estimación del nº total de individuos del grupo G12 hecha desde el lance j
            i=i+1
         enddo
         do while((l13.le.marcas(i)).and.(marcas(i).lt.l21))
            G13(j)=G13(j)+XSIM(i,j)           ! Estimación del nº total de individuos del grupo G13 hecha desde el lance j
            i=i+1
         enddo
         GR1(j) = G11(j) + G12(j) + G13(j)
         do while((l21.le.marcas(i)).and.(marcas(i).lt.l22))
            G21(j)=G21(j)+XSIM(i,j)           ! Estimación del nº total de individuos del grupo G21 hecha desde el lance j
            i=i+1
         enddo
         do while(l22.le.marcas(i))
            G22(j)=G22(j)+XSIM(i,j)           ! Estimación del nº total de individuos del grupo G22 hecha desde el lance j
            i=i+1
         enddo
         GR2(j) = G21(j) + G22(j)
      enddo
      end subroutine Grupos

!***********************************************************************
! Mediana: Calcula la mediana de un vector fila de hasta 150 componentes
!***********************************************************************
      real*8 function Mediana(nl,G)
      integer i, j, ind, nl
      real*8 G(150)
      do i=1,(nl/2 + 1)
         ind = i
         do j=(i+1),nl
           if (G(j).lt.G(ind)) then
              ind=j
           endif
         enddo
         aux=G(i)
         G(i)=G(ind)
         G(ind)=aux
      enddo
      if (nl - 2* (nl/2) == nl) then
         Mediana = (G(nl/2)+G(nl/2 + 1))/2
      else
         Mediana = G(nl/2 + 1)
      endif
      end function Mediana

!***********************************************************************
!                       ESTADÍSTICA BÁSICA
!***********************************************************************
!                            Percentiles
!***********************************************************************

!     call Sort(G,l,NSIM)  donde:   G: Vector a ordenar;
!     l: cantidad de elementos a ordenar; N: longitud prefijada del vector a ordenar
      
      subroutine Sort(G,l,N)
      integer i, j, ind, l, N
      real*8 G(N)
      do i=1,(l-1)
         ind = i
         do j=(i+1),l
           if (G(j).lt.G(ind)) then
              ind=j
           endif
         enddo
         aux=G(i)
         G(i)=G(ind)
         G(ind)=aux
      enddo
      end subroutine 
      
      real*8 function Percent(G,l,N,per)
      integer l, N, per
      real*8 G(N)
         Percent = 0.5*(G(int(l*per/100)+1)+G(-int(-l*per/100))
      end function Percent

      end program Vieira
      
      ! VARIABLES:
      !
      ! ardat1: Guarda el nombre del archivo de datos 1.
      ! texto1: Texto descriptivo (1ª línea) del archivo de datos 1.
      ! encab:  En esta variable se van leyendo los encabezados de los datos que hay en el archivo
      ! nclas1: Número de clases de longitud del archivo de datos 1.
      ! nl1:    Número de lances del archivo de datos 1.
      ! abmin1: Área barrida mínima del archivo de datos 1.
      ! abmax1: Área barrida máxima del archivo de datos 1.
      ! areat1: Área total del archivo de datos 1.
      ! marcas: Vector con las marcas de clase a leer.
      ! X1:     Tabla con los datos numéricos del archivo de datos 1.
      ! PCL1:   Vector de Pesos de la Captura en cada Lance del archivo de datos 1.
      ! PCM1:   Vector de Pesos de la Muestra en cada Lance del archivo de datos 1.
      ! l0,l11,l12,l13,l21,l22: longitudes que sirven para separar los grupos y subgrupos de Vieira.
      ! G0:  l0<=AT<l11   De 16 a 24
      ! G11: l11<=AT<l12  De 25 a 31
      ! G12: l12<=AT<l13  De 32 a 36
      ! G13: l13<=AT<l21  De 37 a 42
      ! G21: l21<=AT<l22  De 43 a 46
      ! G22: l22<=AT      De 47 en adelante
      ! nn1: Vector que acumula el número total de individuos de cada lance del archivo de datos 1.
