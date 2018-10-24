%
% The following are needed in COMMON LISP mode but are provided elsewhere
% For Standard Lisp.  Well actually most of the things here are not
% really part of the public face of Common Lisp but instead they relate
% to the way my implementation tries to share code between a Common and
% a Standard world...

symbolic procedure expand(l, fn);
   if null cdr l then car l
   else list(fn, car l, expand(cdr l, fn));

symbolic procedure deflist(a, b);
   for each v in a do put(car v, b, cadr v);

symbolic procedure global x;
  for each v in x do <<
     make!-global v;
     if not boundp v then set(v, nil) >>;

symbolic procedure fluid x;
  for each v in x do <<
     make!-special v;
     if not boundp v then set(v, nil) >>;

symbolic procedure unglobal x;
  for each v in x do unmake!-global v;

symbolic procedure unfluid x;
  for each v in x do unmake!-special v;

global '(!$eof!$);

!$eof!$ := special!-char 8;

symbolic procedure s!:casetest(val, g);
  if atom val then list('eql, g, mkquote val)
  else if null cdr val then list('eql, g, mkquote car val)
  else 'or . for each p in val collect list('eql, g, mkquote p);

symbolic procedure s!:expand_case(u, g);
  if null u then nil
  else if null cdr u and (eqcar(car u, 't) or eqcar(car u, 'otherwise)) then
     list (t . cdar u)
  else (s!:casetest(caar u, g) . cdar u) . s!:expand_case(cdr u, g);

symbolic macro procedure case(u,!&optional,env);
  begin
    scalar k, g;
    k := cadr u;
    g := gensym();
    u := cddr u;
    return
        list('let,
             list list(g, k),
             'cond . s!:expand_case(u, g))
  end;

end;

