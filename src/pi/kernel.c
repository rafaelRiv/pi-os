#include "pc/uart.h"
#include "rts/buffer.h"
#include "rts/cast.h"
#include "rts/stringOps.h"
#include "rts/cBackend.h"
#include "rts/datatypes.h"
#include "rts/math.h"
#include "rts/memoryManagement.h"
#include "rts/refc_util.h"
#include "rts/runtime.h"
#include "rts/stringOps.h"
#include "rts/tiny-malloc.h"
#include "rts/util.h"

IORef_Storage * global_IORef_Storage;

// function definitions

Value *PrimIO_unsafeCreateWorld
(
    Value * var_0
);

Value *PrimIO_unsafeCreateWorld_arglist(Value_Arglist* arglist);



Value *PrimIO_unsafePerformIO_0
(
    Value * var_0
,   Value * var_1
);

Value *PrimIO_unsafePerformIO_0_arglist(Value_Arglist* arglist);



Value *PrimIO_unsafePerformIO
(
    Value * var_0
);

Value *PrimIO_unsafePerformIO_arglist(Value_Arglist* arglist);

Value *Prelude_IO_prim__putStr(Value *, Value *);

Value *Prelude_IO_prim__putStr_arglist(Value_Arglist* arglist);



Value *Prelude_EqOrd_compareInteger
(
    Value * var_0
,   Value * var_1
);

Value *Prelude_EqOrd_compareInteger_arglist(Value_Arglist* arglist);



Value *Prelude_EqOrd__lt_Ord_Integer
(
    Value * var_0
,   Value * var_1
);

Value *Prelude_EqOrd__lt_Ord_Integer_arglist(Value_Arglist* arglist);



Value *Prelude_EqOrd__eq_eq_Eq_Integer
(
    Value * var_0
,   Value * var_1
);

Value *Prelude_EqOrd__eq_eq_Eq_Integer_arglist(Value_Arglist* arglist);



Value *Prelude_EqOrd_compare_Ord_Integer
(
    Value * var_0
,   Value * var_1
);

Value *Prelude_EqOrd_compare_Ord_Integer_arglist(Value_Arglist* arglist);



Value *Prelude_Types_prim__integerToNat
(
    Value * var_0
);

Value *Prelude_Types_prim__integerToNat_arglist(Value_Arglist* arglist);



Value *Main_main
(
    Value * var_0
);

Value *Main_main_arglist(Value_Arglist* arglist);



Value *prim__sub_Integer
(
    Value * var_0
,   Value * var_1
);

Value *prim__sub_Integer_arglist(Value_Arglist* arglist);



Value *_braceOpen__mainExpression_colon0_braceClose_0
(
    Value * var_0
);

Value *_braceOpen__mainExpression_colon0_braceClose_0_arglist(Value_Arglist* arglist);



Value *__mainExpression_0(void);

Value *__mainExpression_0_arglist(Value_Arglist* arglist);



Value *__mainExpression_0(void)
{
    Value_Arglist *arglist_0 = newArglist(1,1);
    Value *(*closure_1)(Value_Arglist*) = _braceOpen__mainExpression_colon0_braceClose_0_arglist;
    Value * var_0 = (Value*)makeClosureFromArglist(closure_1, arglist_0);
                                                             // (Interactive):1:1--1:1
    // start PrimIO_unsafePerformIO(var_0)                   // (Interactive):1:1--1:1
    Value_Arglist *arglist_2 = newArglist(0,1);
    arglist_2->args[0] =  newReference(var_0);
    Value *(*fPtr_3)(Value_Arglist*) = PrimIO_unsafePerformIO_arglist;
                                                             // (Interactive):1:1--1:1
    Value *closure_3 = (Value*)makeClosureFromArglist(fPtr_3, arglist_2);
                                                             // (Interactive):1:1--1:1
    // end   PrimIO_unsafePerformIO(var_0)                   // (Interactive):1:1--1:1
    Value *returnValue = closure_3;
    removeReference(var_0);
    return returnValue;
}


Value *__mainExpression_0_arglist(Value_Arglist* arglist)
{
    return __mainExpression_0
        (
        );
}


Value *_braceOpen__mainExpression_colon0_braceClose_0
(
    Value * var_0
)
{
    // start Main_main(var_0)
    Value_Arglist *arglist_4 = newArglist(0,1);
    arglist_4->args[0] =  newReference(var_0);
    Value *(*fPtr_5)(Value_Arglist*) = Main_main_arglist;
    Value *closure_5 = (Value*)makeClosureFromArglist(fPtr_5, arglist_4);
    // end   Main_main(var_0)
    Value *returnValue = closure_5;
    return returnValue;
}


Value *_braceOpen__mainExpression_colon0_braceClose_0_arglist(Value_Arglist* arglist)
{
    return _braceOpen__mainExpression_colon0_braceClose_0
        (
              arglist->args[0]
        );
}



Value *prim__sub_Integer
(
    Value * var_0
,   Value * var_1
)
{
    Value *returnValue = sub_Integer(var_0, var_1);
    return returnValue;
}


Value *prim__sub_Integer_arglist(Value_Arglist* arglist)
{
    return prim__sub_Integer
        (
              arglist->args[0]
            , arglist->args[1]
        );
}




Value *Main_main
(
    Value * var_0
)
{
    Value * var_1 = (Value*)makeString("Hello World\x0a"""); // Prelude.IO:98:22--98:34
    // start Prelude_IO_prim__putStr(var_1, var_0)           // Prelude.IO:98:22--98:34
    Value_Arglist *arglist_6 = newArglist(0,2);
    arglist_6->args[0] =  newReference(var_1);
    arglist_6->args[1] =  newReference(var_0);
    Value *(*fPtr_7)(Value_Arglist*) = Prelude_IO_prim__putStr_arglist;
                                                             // Prelude.IO:98:22--98:34
    Value *closure_7 = (Value*)makeClosureFromArglist(fPtr_7, arglist_6);
                                                             // Prelude.IO:98:22--98:34
    // end   Prelude_IO_prim__putStr(var_1, var_0)           // Prelude.IO:98:22--98:34
    Value *returnValue = closure_7;
    removeReference(var_1);
    return returnValue;
}


Value *Main_main_arglist(Value_Arglist* arglist)
{
    return Main_main
        (
              arglist->args[0]
        );
}




Value *Prelude_Types_prim__integerToNat
(
    Value * var_0
)
{
    Value * var_1 = (Value*)makeIntegerLiteral("0");
    Value * var_2 = lte_Integer(var_1, var_0);               // Prelude.Basics:154:13--154:16
    Value * tmp_8 = NULL;                                    // Prelude.Basics:154:13--154:16
    switch(extractInt(var_2)){                               // Prelude.Basics:154:13--154:16
      case 0 :
      {
        tmp_8 = (Value*)makeIntegerLiteral("0");
        break;
      }
      default :
      {
        tmp_8 = newReference(var_0);
      }
    }
    Value *returnValue = tmp_8;
    removeReference(var_2);
    removeReference(var_1);
    return returnValue;
}


Value *Prelude_Types_prim__integerToNat_arglist(Value_Arglist* arglist)
{
    return Prelude_Types_prim__integerToNat
        (
              arglist->args[0]
        );
}




Value *Prelude_EqOrd_compare_Ord_Integer
(
    Value * var_0
,   Value * var_1
)
{
    // start Prelude_EqOrd__lt_Ord_Integer(var_0, var_1)     // Prelude.EqOrd:174:1--179:47
    Value_Arglist *arglist_9 = newArglist(0,2);
    arglist_9->args[0] =  newReference(var_0);
    arglist_9->args[1] =  newReference(var_1);
    Value *(*fPtr_10)(Value_Arglist*) = Prelude_EqOrd__lt_Ord_Integer_arglist;
                                                             // Prelude.EqOrd:174:1--179:47
    Value *closure_10 = (Value*)makeClosureFromArglist(fPtr_10, arglist_9);
                                                             // Prelude.EqOrd:174:1--179:47
    // end   Prelude_EqOrd__lt_Ord_Integer(var_0, var_1)     // Prelude.EqOrd:174:1--179:47
    Value * var_3 = trampoline(closure_10);                  // Prelude.EqOrd:121:21--121:25
    Value * tmp_11 = NULL;                                   // Prelude.EqOrd:121:21--121:25
    switch(extractInt(var_3)){                               // Prelude.EqOrd:121:21--121:25
      case 1 :
      {
        tmp_11 = (Value*)makeBits8(UINT8_C(0));
        break;
      }
      case 0 :
      {
        // start Prelude_EqOrd__eq_eq_Eq_Integer(var_0, var_1)
                                                             // Prelude.EqOrd:43:1--45:44
        Value_Arglist *arglist_12 = newArglist(0,2);
        arglist_12->args[0] =  newReference(var_0);
        arglist_12->args[1] =  newReference(var_1);
        Value *(*fPtr_13)(Value_Arglist*) = Prelude_EqOrd__eq_eq_Eq_Integer_arglist;
                                                             // Prelude.EqOrd:43:1--45:44
        Value *closure_13 = (Value*)makeClosureFromArglist(fPtr_13, arglist_12);
                                                             // Prelude.EqOrd:43:1--45:44
        // end   Prelude_EqOrd__eq_eq_Eq_Integer(var_0, var_1)
                                                             // Prelude.EqOrd:43:1--45:44
        Value * var_2 = trampoline(closure_13);              // Prelude.EqOrd:18:22--18:26
        Value * tmp_14 = NULL;                               // Prelude.EqOrd:18:22--18:26
        switch(extractInt(var_2)){                           // Prelude.EqOrd:18:22--18:26
          case 1 :
          {
            tmp_14 = (Value*)makeBits8(UINT8_C(1));
            break;
          }
          case 0 :
          {
            tmp_14 = (Value*)makeBits8(UINT8_C(2));
            break;
          }
        }
        tmp_11 = tmp_14;
        removeReference(var_2);
        break;
      }
    }
    Value *returnValue = tmp_11;
    removeReference(var_3);
    return returnValue;
}


Value *Prelude_EqOrd_compare_Ord_Integer_arglist(Value_Arglist* arglist)
{
    return Prelude_EqOrd_compare_Ord_Integer
        (
              arglist->args[0]
            , arglist->args[1]
        );
}




Value *Prelude_EqOrd__eq_eq_Eq_Integer
(
    Value * var_0
,   Value * var_1
)
{
    Value * var_2 = eq_Integer(var_0, var_1);                // Prelude.Basics:154:13--154:16
    Value * tmp_15 = NULL;                                   // Prelude.Basics:154:13--154:16
    switch(extractInt(var_2)){                               // Prelude.Basics:154:13--154:16
      case 0 :
      {
        tmp_15 = (Value*)makeBits8(UINT8_C(0));
        break;
      }
      default :
      {
        tmp_15 = (Value*)makeBits8(UINT8_C(1));
      }
    }
    Value *returnValue = tmp_15;
    removeReference(var_2);
    return returnValue;
}


Value *Prelude_EqOrd__eq_eq_Eq_Integer_arglist(Value_Arglist* arglist)
{
    return Prelude_EqOrd__eq_eq_Eq_Integer
        (
              arglist->args[0]
            , arglist->args[1]
        );
}




Value *Prelude_EqOrd__lt_Ord_Integer
(
    Value * var_0
,   Value * var_1
)
{
    Value * var_2 = lt_Integer(var_0, var_1);                // Prelude.Basics:154:13--154:16
    Value * tmp_16 = NULL;                                   // Prelude.Basics:154:13--154:16
    switch(extractInt(var_2)){                               // Prelude.Basics:154:13--154:16
      case 0 :
      {
        tmp_16 = (Value*)makeBits8(UINT8_C(0));
        break;
      }
      default :
      {
        tmp_16 = (Value*)makeBits8(UINT8_C(1));
      }
    }
    Value *returnValue = tmp_16;
    removeReference(var_2);
    return returnValue;
}


Value *Prelude_EqOrd__lt_Ord_Integer_arglist(Value_Arglist* arglist)
{
    return Prelude_EqOrd__lt_Ord_Integer
        (
              arglist->args[0]
            , arglist->args[1]
        );
}




Value *Prelude_EqOrd_compareInteger
(
    Value * var_0
,   Value * var_1
)
{
    // start Prelude_EqOrd_compare_Ord_Integer(var_0, var_1) // Prelude.EqOrd:174:1--179:47
    Value_Arglist *arglist_17 = newArglist(0,2);
    arglist_17->args[0] =  newReference(var_0);
    arglist_17->args[1] =  newReference(var_1);
    Value *(*fPtr_18)(Value_Arglist*) = Prelude_EqOrd_compare_Ord_Integer_arglist;
                                                             // Prelude.EqOrd:174:1--179:47
    Value *closure_18 = (Value*)makeClosureFromArglist(fPtr_18, arglist_17);
                                                             // Prelude.EqOrd:174:1--179:47
    // end   Prelude_EqOrd_compare_Ord_Integer(var_0, var_1) // Prelude.EqOrd:174:1--179:47
    Value *returnValue = closure_18;
    return returnValue;
}


Value *Prelude_EqOrd_compareInteger_arglist(Value_Arglist* arglist)
{
    return Prelude_EqOrd_compareInteger
        (
              arglist->args[0]
            , arglist->args[1]
        );
}


Value *Prelude_IO_prim__putStr_arglist(Value_Arglist* arglist)
{
    return Prelude_IO_prim__putStr
        (
              arglist->args[0]
            , arglist->args[1]
        );
}


Value *Prelude_IO_prim__putStr
(
      Value *var_1
    , Value *var_2
)
{
     // ffi call to idris2_putStr
    idris2_putStr(((Value_String*)var_1)->str);
    return NULL;
}


Value *PrimIO_unsafePerformIO
(
    Value * var_0
)
{
    Value * var_1 = newReference(var_0);                     // PrimIO:104:19--104:23
    Value_Arglist *arglist_19 = newArglist(1,2);
    arglist_19->args[0] =  newReference(var_1);
    Value *(*closure_20)(Value_Arglist*) = PrimIO_unsafePerformIO_0_arglist;
                                                             // PrimIO:106:27--106:28
    Value * var_2 = (Value*)makeClosureFromArglist(closure_20, arglist_19);
                                                             // PrimIO:106:7--106:24
    // start PrimIO_unsafeCreateWorld(var_2)                 // PrimIO:106:7--106:24
    Value_Arglist *arglist_21 = newArglist(0,1);
    arglist_21->args[0] =  newReference(var_2);
    Value *(*fPtr_22)(Value_Arglist*) = PrimIO_unsafeCreateWorld_arglist;
                                                             // PrimIO:106:7--106:24
    Value *closure_22 = (Value*)makeClosureFromArglist(fPtr_22, arglist_21);
                                                             // PrimIO:106:7--106:24
    // end   PrimIO_unsafeCreateWorld(var_2)                 // PrimIO:106:7--106:24
    Value *returnValue = closure_22;
    removeReference(var_2);
    removeReference(var_1);
    return returnValue;
}


Value *PrimIO_unsafePerformIO_arglist(Value_Arglist* arglist)
{
    return PrimIO_unsafePerformIO
        (
              arglist->args[0]
        );
}




Value *PrimIO_unsafePerformIO_0
(
    Value * var_0
,   Value * var_1
)
{
    Value * var_2 = apply_closure(var_0, var_1);             // PrimIO:14:30--14:37
    Value *returnValue = newReference(var_2);
    removeReference(var_2);
    return returnValue;
}


Value *PrimIO_unsafePerformIO_0_arglist(Value_Arglist* arglist)
{
    return PrimIO_unsafePerformIO_0
        (
              arglist->args[0]
            , arglist->args[1]
        );
}




Value *PrimIO_unsafeCreateWorld
(
    Value * var_0
)
{
    Value * var_1 = (Value*)makeWorld();                     // PrimIO:97:1--97:53
    Value *returnValue = tailcall_apply_closure(var_0, var_1);
    removeReference(var_1);
    return returnValue;
}


Value *PrimIO_unsafeCreateWorld_arglist(Value_Arglist* arglist)
{
    return PrimIO_unsafeCreateWorld
        (
              arglist->args[0]
        );
}



// main function

/*
int main(int argc, char *argv[])
{
    idris2_setArgs(argc, argv);
    global_IORef_Storage = NULL;
    Value *mainExprVal = __mainExpression_0();
    trampoline(mainExprVal);
    return 0; // bye bye
} */


void kmain(void) {
  print("execute kmain\n");
  init();
}
