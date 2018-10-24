%
% Parts of the CCL compiler that are specific to Common Lisp. This
% file is only useful as an add-on to "$cslbase/compiler.red"
%
%       Copyright (C) Codemist Ltd, 1990-2002
%

%
% This code may be used and modified, and redistributed in binary
% or source form, subject to the "CCL Public License", which should
% accompany it. This license is a variant on the BSD license, and thus
% permits use of code derived from this in either open and commercial
% projects: but it does require that updates to this code be made
% available back to the originators of the package.
% Before merging other code in with this or linking this code
% with other packages or libraries please check that the license terms
% of the other material are compatible with those of this.
%


flag('(make!-package in!-package shadow shadowing!-import export
       unexport use!-package unuse!-package import), 'eval);


symbolic macro procedure s!:compilermacro(u, !&optional, env);
  begin
    scalar name, g;
    name := car (u := cdr u);
    g := gensym();
    return list('compd,
                mkquote name,
                ''s!:compilermacro,
                mkquote list('lambda, g . '(env context),
                   list('let!*,
                      for each v in cadr u collect
                         list(v, 
                            list('car,
                               list('setq, g, list('cdr, g)))),
                      'progn . cddr u)))
  end;

symbolic procedure s!:xmember(x, env, context);
  begin
    return nil
  end;

put('member, 's!:compilermacro, function s!:xmember);

symbolic procedure s!:findmacro(x, env, context);
  begin
    scalar w, a, b, tt, ff;
    w := cdr x;
    a := car w; w := cdr w;
    b := car w; w := cdr w;
    if null w then return nil;  % No keyword specials
    tt := car w; if null (w := cdr w) then return nil;
    ff := car w; w := cdr w;
    if w then return nil;       % more than one keyword thingy
    if tt = '!:test and
       (ff = '(quote char!=) or
        ff = '(function char!=)) then return list('find!-char!=, a, b);
    return nil
  end;

put('find, 's!:compilermacro, function s!:findmacro);

symbolic procedure s!:imp_svref x;
  if !*carcheckflag then 'getv . cdr x
  else 'qgetv . cdr x;

put('svref, 's!:tidy_fn, function s!:imp_svref);

symbolic procedure s!:imp_the u;
    s!:improve caddr u;

put('the, 's!:tidy_fn, 's!:imp_the);

symbolic procedure s!:c!+ x;
   s!:improve (if null cddr x then cadr x else 'plus . cdr x);

put('!+, 's!:tidy_fn, function s!:c!+);

symbolic procedure s!:c!- x;
   if null cddr x then s!:improve list('minus, cadr x)
   else s!:improve('difference . cdr x);

put('!-, 's!:tidy_fn, function s!:c!-);

symbolic procedure s!:c!* x;
   s!:improve (if null cddr x then cadr x else 'times . cdr x);

put('!*, 's!:tidy_fn, function s!:c!*);

symbolic procedure s!:c!< x;
   s!:improve ('lessp . cdr x);

put('!<, 's!:tidy_fn, function s!:c!<);

symbolic procedure s!:c!> x;
   s!:improve ('greaterp . cdr x);

put('!>, 's!:tidy_fn, function s!:c!>);

symbolic procedure s!:cfirst x;
   s!:improve ('car . cdr x);

put('first, 's!:tidy_fn, function s!:cfirst);

symbolic procedure s!:crest x;
   s!:improve ('cdr . cdr x);

put('rest, 's!:tidy_fn, function s!:crest);

symbolic procedure s!:csecond x;
   s!:improve ('cadr . cdr x);

put('second, 's!:tidy_fn, function s!:csecond);

symbolic procedure s!:cthird x;
   s!:improve ('caddr . cdr x);

put('third, 's!:tidy_fn, function s!:cthird);

symbolic procedure s!:cfourth x;
   s!:improve ('cadddr . cdr x);

put('fourth, 's!:tidy_fn, function s!:cfourth);

% At least for Axiom some of the string comparison functions are
% important, and especially the cases where no keyword arguments are
% involved. I improve performance for them by mapping calls that only
% have the mandatory arguments onto calls to versions implemented directly
% in the CCL kernel. While Axiom does not use ALL of these it seems cleanest
% to cover everything while I am about it.

symbolic procedure s!:cstring!< x;
   if length x = 3 then s!:improve ('string!<2 . cdr x)
   else x;

put('string!<, 's!:tidy_fn, function s!:cstring!<);

symbolic procedure s!:cstring!> x;
   if length x = 3 then s!:improve ('string!>2 . cdr x)
   else x;

put('string!>, 's!:tidy_fn, function s!:cstring!>);

symbolic procedure s!:cstring!= x;
   if length x = 3 then s!:improve ('string!=2 . cdr x)
   else x;

put('string!=, 's!:tidy_fn, function s!:cstring!=);

symbolic procedure s!:cstring!/!= x;
   if length x = 3 then s!:improve ('string!/!=2 . cdr x)
   else x;

put('string!/!=, 's!:tidy_fn, function s!:cstring!/!=);

symbolic procedure s!:cstring!<!= x;
   if length x = 3 then s!:improve ('string!<!=2 . cdr x)
   else x;

put('string!<!=, 's!:tidy_fn, function s!:cstring!<!=);

symbolic procedure s!:cstring!>!= x;
   if length x = 3 then s!:improve ('string!>!=2 . cdr x)
   else x;

put('string!>!=, 's!:tidy_fn, function s!:cstring!>!=);

symbolic procedure s!:cstring!-lessp x;
   if length x = 3 then s!:improve ('string!-lessp2 . cdr x)
   else x;

put('string!-lessp, 's!:tidy_fn, function s!:cstring!-lessp);

symbolic procedure s!:cstring!-greaterp x;
   if length x = 3 then s!:improve ('string!-greaterp2 . cdr x)
   else x;

put('string!-greaterp, 's!:tidy_fn, function s!:cstring!-greaterp);

symbolic procedure s!:cstring!-equal x;
   if length x = 3 then s!:improve ('string!-equal2 . cdr x)
   else x;

put('string!-equal, 's!:tidy_fn, function s!:cstring!-equal);

symbolic procedure s!:cstring!-not!-equal x;
   if length x = 3 then s!:improve ('string!-not!-equal2 . cdr x)
   else x;

put('string!-not!-equal, 's!:tidy_fn, function s!:cstring!-not!-equal);

symbolic procedure s!:cstring!-not!-greaterp x;
   if length x = 3 then s!:improve ('string!-not!-greaterp2 . cdr x)
   else x;

put('string!-not!-greaterp, 's!:tidy_fn, function s!:cstring!-not!-greaterp);

symbolic procedure s!:cstring!-not!-lessp x;
   if length x = 3 then s!:improve ('string!-not!-lessp2 . cdr x)
   else x;

put('string!-not!-lessp, 's!:tidy_fn, function s!:cstring!-not!-lessp);

symbolic procedure s!:cwrite x;
   if length x = 2 then s!:improve ('write!-1 . cdr x)
   else x;

put('write, 's!:tidy_fn, function s!:cwrite);

symbolic procedure s!:cwrite!-to!-string x;
   if length x = 2 then s!:improve ('write!-to!-string!-1 . cdr x)
   else x;

put('write!-to!-string, 's!:tidy_fn, function s!:cwrite!-to!-string);

symbolic procedure s!:cdelete!-duplicates x;
   if length x = 2 then s!:improve ('delete!-duplicates!-1 . cdr x)
   else x;

put('delete!-duplicates, 's!:tidy_fn, function s!:cdelete!-duplicates);

symbolic procedure s!:cremove!-duplicates x;
   if length x = 4 and
      caddr x = !:test and
      (cadddr x = '(function equalp) or
       cadddr x = '(quote equalp) or
       cadddr x = 'equalp) then
        s!:improve list('remove!-duplicates!-1, cadr x)
   else x;

put('remove!-duplicates, 's!:tidy_fn, function s!:cremove!-duplicates);

symbolic procedure s!:csearch x;
   if length x = 3 then s!:improve ('search!-2 . cdr x)
   else x;

put('search, 's!:tidy_fn, function s!:csearch);

symbolic procedure s!:csort x;
   if length x = 3 then s!:improve ('sort!-2 . cdr x)
   else x;

put('sort, 's!:tidy_fn, function s!:csort);

symbolic procedure s!:cstable!-sort x;
   if length x = 3 then s!:improve ('stable!-sort!-2 . cdr x)
   else x;

put('stable!-sort, 's!:tidy_fn, function s!:cstable!-sort);

symbolic procedure s!:cmerge x;
   if length x = 5 then s!:improve ('merge!-4 . cdr x)
   else x;

put('merge, 's!:tidy_fn, function s!:cmerge);

symbolic procedure s!:cwrite!-line x;
   if length x < 4 then s!:improve ('write!-line!-2 . cdr x)
   else x;

put('write!-line, 's!:tidy_fn, function s!:cwrite!-line);


symbolic procedure s!:cmake!-array x;
   if length x = 2 then s!:improve ('make!-array!-1 . cdr x)
   else x;

put('make!-array, 's!:tidy_fn, function s!:cmake!-array);

symbolic procedure s!:testeql(neg, x, env, lab);
  begin
    scalar a, b;
    a := cadr x;
    b := caddr x;
% eql tests against nil can be optimised
    if null a then s!:jumpif(not neg, b, env, lab)
    else if null b then s!:jumpif(not neg, a, env, lab)
% comparisons involving a literal identifier or (in this
% Lisp implementation) a fixnum can be turned into uses of
% eq rather than equal, to good effect.
    else if (eqcar(a, 'quote) and (symbolp cadr a or eq!-safe cadr a)) or
            (eqcar(b, 'quote) and (symbolp cadr b or eq!-safe cadr b)) or
            eq!-safe a or eq!-safe b then
        s!:testeq(neg, x, env, lab)
   else <<
      s!:load2(a, b, env);    % args commute here if that helps
      s!:outopcode1('BUILTIN2, get('eql, 's!:builtin2), 'eql);
      if neg then s!:outjump('JUMPT, lab)
      else s!:outjump('JUMPNIL, lab) >>
  end;

put('eql, 's!:testfn, function s!:testeql);

symbolic procedure s!:imp_typep x;
  begin
    scalar a1, a2, w;
    a1 := s!:improve cadr x;
    a2 := s!:improve caddr x;
    if null a2 then return nil;
    x := list('typep, a1, a2);
    if eqcar(a2, 'quote) then <<
        a2 := cadr a2;
        if atom a2 and (w := get(a2, 's!:typep_checker)) then x := list(w, a1)
        else if a2 = t then x := t
        else if null a2 then x := nil
        else if eqcar(a2, 'or) then <<
            w := gensym();
            x := list('let, list list(w, a1),
                'or . for each p in cdr a2 collect
                         s!:improve list('typep, w, mkquote p)) >> >>;
    return x
  end;

deflist('(
   (null             null)
   (simple!-string   simple!-string!-p)
   (string           stringp)
   (list             listp)
   (pair             consp)
   (symbol           symbolp)
   (vector           vectorp)
   (simple!-vector   simple!-vector!-p)
   (integer          integerp)
   (float            floatp)
   (short!-float     short!-floatp)
   (single!-float    single!-floatp)
   (double!-float    double!-floatp)
   (long!-float      long!-floatp)
   (number           numberp)
   ), 's!:typep_checker);

put('typep, 's!:tidy_fn, function s!:imp_typep);

end;

