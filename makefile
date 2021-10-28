cc = gcc
prom = Simonsays
deps = queue.h menu.h queue.h simonLoad.h simonMove.h
obj = main.o menu.o queue.o simonLoad.o simonMove.o
$(prom): $(obj)
	$(cc) -o $(prom) $(obj)

$.o: %.c $(deps)
	$(cc) -c $< -o $@

clean:
	rm -rf $(obj) $(prom)
