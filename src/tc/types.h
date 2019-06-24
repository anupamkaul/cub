#ifndef types_h
#define types_h

#include "symbols.h"

/* Types.h  - 
 * This module contains the definitions of the 
 * types in tiger. Each type will be recorded
 * and classified.
 *
 * It is this classification that helps in the
 * type check.
 *
 * Following are the different types:
 * 1. Ty_Int
 * 2. Ty_String
 * 3. Ty_Record
 * 4. Ty_Array
 * 5. Ty_Name (which could be further resolved)
 * 6. Ty_Void (for expressions that don't return a type)
 * 7. Ty_Nil
 */

typedef struct Ty_ty_* Ty_ty;
typedef struct Ty_fieldList_ *Ty_fieldList;
typedef struct Ty_field_* Ty_field;
typedef struct Ty_tyList_* Ty_tyList;

struct Ty_ty_
{
    enum 
    {      
	ty_Int,
	ty_String,
	ty_Record,
        ty_Array,
    	ty_Name,
        ty_Void,	
	ty_Nil
    } type;
    	
    union
    {
	Ty_fieldList record;
	Ty_ty array;
	struct name_
	{
	    symbol sym;
	    Ty_ty  ty;
	} name;	    
    } u;
};

struct Ty_fieldList_
{
    Ty_field head;
    Ty_fieldList tail;
};

struct Ty_field_
{
    symbol sym;
    Ty_ty  ty;
};

struct Ty_tyList_
{
    Ty_ty head;
    Ty_tyList tail;
};

/* constructors for inserting the types */

Ty_ty Ty_Int(void);
Ty_ty Ty_String(void);
Ty_ty Ty_Nil(void);
Ty_ty Ty_Void(void);

Ty_ty Ty_Record(Ty_fieldList fields);
Ty_ty Ty_Array(Ty_ty ty);
Ty_ty Ty_Name(symbol sym, Ty_ty ty);

/* constructors for other internal structs */

Ty_fieldList Ty_FieldList(Ty_field head, Ty_fieldList tail);
Ty_tyList    Ty_TyList(Ty_ty ty, Ty_tyList tail);
Ty_field     Ty_Field(symbol sym, Ty_ty ty);

#endif
