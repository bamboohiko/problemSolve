program p2;
  type data=record a,b,c:longint;end;
  var min,gw,i,j,k,n:longint;
      e:data;
      g:array[0..101,0..101] of longint;
      s:array[0..101] of boolean;
begin
  assign(input,'t1.in');
  assign(output,'t1.out');
  reset(input);
  rewrite(output);
  readln(n);
  for i:=1 to n do
    for j:=1 to n do read(g[i,j]);
  for i:=1 to n do s[i]:=false;
  s[1]:=true;
  gw:=0;
  for i:=1 to n-1 do
    begin
      min:=maxlongint;
      for j:=1 to n do
        if s[j] then
          for k:=1 to n do
            if (g[j,k]<>0) and (not s[k]) and (g[j,k]<min) then
              begin
                e.a:=j;e.b:=k;e.c:=g[j,k];
                min:=g[j,k];
              end;
      s[e.b]:=true;
      gw:=gw+e.c;
    end;
  writeln(gw);
  close(input);
  close(output);
end.
