plotonda.png: datosonda.dat MontanaAna_Ej29.py
	python MontanaAna_Ej29.py 


datosonda.dat: MontanaAna_Ej29.x
	./MontanaAna_Ej29.x 

MontanaAna_Ej29.x: MontanaAna_Ej29.cpp
	g++ MontanaAna_Ej29.cpp -o MontanaAna_Ej29.x

clean: 
	rm -rf MontanaAna_Ej29.x datosonda.dat plotonda.png

