
--  Copyright (c) 1991-2002, The Numerical Algorithms Group Ltd.
--  All rights reserved.
--  
--  Redistribution and use in source and binary forms, with or without
--  modification, are permitted provided that the following conditions are
--  met:
--  
--      - Redistributions of source code must retain the above copyright
--        notice, this list of conditions and the following disclaimer.
--  
--      - Redistributions in binary form must reproduce the above copyright
--        notice, this list of conditions and the following disclaimer in
--        the documentation and/or other materials provided with the
--        distribution.
--  
--      - Neither the name of The Numerical ALgorithms Group Ltd. nor the
--        names of its contributors may be used to endorse or promote products
--        derived from this software without specific prior written permission.
--  
--  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
--  IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
--  TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
--  PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
--  OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
--  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
--  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES-- LOSS OF USE, DATA, OR
--  PROFITS-- OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
--  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
--  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
--  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


)package 'BOOTTRAN
bpStruct()==
   bpEqKey "STRUCTURE" and
      (bpName() or bpTrap()) and
        (bpEqKey "DEF" or bpTrap()) and
           bpTypeList() and bpPush bfStruct(bpPop2(),bpPop1())
 
bpTypeList() == bpPileBracketed function bpTypeItemList
       or bpTerm() and bpPush [bpPop1()]
 
bpTypeItemList() ==  bpListAndRecover function bpTerm
 
bpTerm() ==
          (bpName() or bpTrap()) and
            ((bpParenthesized function bpIdList and
              bpPush bfNameArgs (bpPop2(),bpPop1()))
                or bpName() and bpPush bfNameArgs(bpPop2(),bpPop1()))
                 or bpPush(bfNameOnly bpPop1())
 
bpIdList()== bpTuple function bpName
 
bfNameOnly x==
      if x="t"
      then ["T"]
      else  [x]
 
bfNameArgs (x,y)==
    y:=if EQCAR(y,"TUPLE") then CDR y else [y]
    cons(x,y)
 
bfStruct(name,arglist)==
  bfTuple [bfCreateDef i for i in arglist]
 
bfCreateDef x==
     if null cdr x
     then
       f:=car x
       ["SETQ",f,["LIST",["QUOTE",f]]]
     else
       a:=[bfGenSymbol() for i in cdr x]
       ["DEFUN",car x,a,["CONS",["QUOTE",car x],["LIST",:a]]]
 
bpCase()==
      bpEqKey "CASE" and
        (bpWhere() or bpTrap()) and
           (bpEqKey "OF" or bpMissing "OF") and
                 bpPiledCaseItems()
 
bpPiledCaseItems()==
   bpPileBracketed function bpCaseItemList and
       bpPush bfCase(bpPop2(),bpPop1())
bpCaseItemList()==
   bpListAndRecover function bpCaseItem
 
bpCaseItem()==
    (bpTerm() or bpTrap()) and
       (bpEqKey "EXIT" or bpTrap()) and
         (bpWhere() or bpTrap()) and
            bpPush bfCaseItem (bpPop2(),bpPop1())
 
bfCaseItem(x,y)==[x,y]
 
bfCase(x,y)==
         g:=bfGenSymbol()
         g1:=bfGenSymbol()
         a:=bfLET(g,x)
         b:=bfLET(g1,["CDR",g])
         c:=bfCaseItems (g1,y)
         bfMKPROGN [a,b,["CASE",["CAR", g],:c]]
 
bfCaseItems(g,x)==  [bfCI(g,i,j) for [i,j] in x]
 
bfCI(g,x,y)==
    a:=cdr x
    if null a
    then [car x,y]
    else
       b:=[[i,bfCARCDR(j,g)] for i in a for j in 0..]
       [car x,["LET",b,y]]
 
bfCARCDR (n,g)==[INTERN CONCAT ('"CA",bfDs n,'"R"),g]
 
bfDs n== if n=0 then '"" else CONCAT('"D",bfDs(n-1))
 
 
 
 
