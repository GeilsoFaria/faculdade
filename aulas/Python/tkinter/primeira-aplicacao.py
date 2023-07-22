from tkinter import * #  "*" importa tudo

menu_inicial = Tk() #instacia um objeto menu_inicial da classe Tk
menu_inicial.title("Primeiro app")#define título da janela
menu_inicial.geometry("500x250+50+200") #500=largura, 250=altura,50=posInicialX,200=posInicialY
menu_inicial.resizable(TRUE,1) #valores booleanos p/ definir se poderá redimensionar a janela (X,Y)

#menu_inicial.minsize(500,250) #Tamanho minimo janela(largura,altura)
#menu_inicial.maxsize(600,300) #Tamanho maximo janela(largura,altura)

#menu_inicial.state("zoomed") #zoomed=cria uma janela de tamanho maximo, iconic=cria minimizada
menu_inicial.iconbitmap("imagens/icon.ico") #muda icone da janela
menu_inicial.mainloop()#mantem janela aberta
