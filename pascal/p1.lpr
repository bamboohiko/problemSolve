program p1;
type data=record
  l,r,sl,sr,v,f,lazy:longint;
end;
var pos,n,q,i,x,y,p:longint;
    ch:char;
    num:array[0..100001]of longint;
    tree:array[0..300001]of data;
function maketree(var node:longint; a,b:longint):longint;
var mid,t1,t2:longint;
begin
  node:=pos;
  inc(pos);
  tree[node].lazy := 0;
  tree[node].l:=a;
  tree[node].r:=b;
  if a=b then
    begin
      tree[node].v:=num[a];
      exit(tree[node].v);
    end;
  mid:=(a+b)div 2;
  t1:=maketree(tree[node].sl,a,mid);
  t2:=maketree(tree[node].sr,mid+1,b);
  tree[node].v:=t1+t2;
  //writeln(tree[node].sl,' ',tree[node].sr);
  exit(tree[node].v);
end;
function sum(node,a,b:longint):longint;
var mid,t1,t2:longint;
begin
  t1 := 0;t2 := 0;
  if (a<=tree[node].l)and(b>=tree[node].r) then exit(tree[node].v);
  mid:=(tree[node].l+tree[node].r)div 2;
  tree[tree[node].sl].lazy := tree[node].lazy;
  tree[tree[node].sl].v := tree[node].lazy*(mid-tree[node].l+1);
  tree[tree[node].sr].lazy := tree[node].lazy;
  tree[tree[node].sr].v := tree[node].lazy*(tree[node].r-mid);
  tree[node].lazy := 0;
  if a<=mid then t1:=sum(tree[node].sl,a,b);
  if b>mid then t2:=sum(tree[node].sr,a,b);
  exit(t1+t2);
end;
procedure add(node,a,b,c:longint);
var mid:longint;
begin
  if (a<=tree[node].l)and(b>=tree[node].r) then
    begin
      tree[node].lazy:=c;
      tree[node].v:=tree[node].v+c*(tree[node].r-tree[node].l+1);
      exit;
    end;
  mid:=(tree[node].l+tree[node].r)div 2;
  tree[tree[node].sl].lazy := tree[node].lazy;
  tree[tree[node].sl].v := tree[node].lazy*(mid-tree[node].l+1);
  tree[tree[node].sr].lazy := tree[node].lazy;
  tree[tree[node].sr].v := tree[node].lazy*(tree[node].r-mid);
  tree[node].lazy := 0;
  if a<=mid then add(tree[node].sl,a,b,c);
  if b>mid then add(tree[node].sr,a,b,c);
  tree[node].v:=tree[tree[node].sl].v+tree[tree[node].sr].v;
end;
begin
  //assign(input,'d.in');
  //reset(input);
  //assign(output,'d.out');
  //rewrite(output);
  readln(n,q);
  for i:=1 to n do read(num[i]);
  readln;
  pos:=1;
  maketree(p,1,n);
  writeln(pos);
  for i:=1 to q do
    begin
      read(ch);
      if ch='Q' then
        begin
          readln(x,y);
          writeln(sum(1,x,y));
        end;
      if ch='C' then
        begin
          readln(x,y,p);
          add(1,x,y,p);
        end;
    end;
  //close(input);
  //close(output);
end.
