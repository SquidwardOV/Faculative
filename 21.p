uses crt;
var k,m,c:longint;
begin
clrscr;
writeln('vvedite kol-vo sekund');
readln(k);
c:=k div 3600;
m:=(k-(c*3600)) div 60;
write('Proshlo ',c,' chasov ',m,' minut');
readkey;
end.
