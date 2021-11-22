%Aluno *Daniela Soares de OLiveira*, Matricula  *180015222*

# Questão 1
.
Não, o tratamento de page faults tem que ta sempre residente na memoria principal, caso não esteja é possivel realizar o page in quando for necessario.
# Questão 2
## Item A
### Subitem 1
.
001 0000 0000 0111
### Subitem 2
.
011 0000 1010 0000
### Subitem 3
.
110 0000 0000 0101
### Subitem 4
.
page fault
### Subitem 5
.
010 0000 0000 0000
## Item B
.
Não é possivel ser externo mas interno sim, pois por exemplo quando uma pagina precisa de 4k e ela pega 6k pois é o que tem, vai ter uma perda de 2k. A fragmentação interna é isso é a perda de espaço.
# Questão 3
.
Sim, pois qualquer emulador de sistema que emula um sistema contendo um MMU efetivamente emula um MMU no software.
# Questão 4
## Item A
.
A funcao_a.
## Item B
.
O segundo laço vai demandar muito mais de disco que o primeiro, pois o laço B começa a interação em j em vez de acessar a primeira linha qualquer e depois pecorre as colunas, a cada interação que ele for fazer do laço interno , ele acessou todos os quadros livres e teve que matar um dos quadros e coloca por disco para carregar o novo quadro na ram. Por isso deu quadro Miss em todas as consultas alem disse vai dar TLB Miss tbm.


