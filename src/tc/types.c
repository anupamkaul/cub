/* Types.c 
 *
 * Implements any required
 * functionality of types.h
 */

#include <stdlib.h>
#include "types.h"

/* Note - my gcc had a bug and could not resolve
 * the symbols Ty_Int (type enum of Ty_Ty) and 
 * Ty_Int (function name of constructor), so I
 * had to resolve the first Ty_Int to ty_Int ! 
 */

/* constructors for inserting the types */

Ty_ty Ty_Int(void)
{
    Ty_ty ty = (Ty_ty)malloc(sizeof(struct Ty_ty_));
    ty->type = ty_Int;
    return ty;
}

Ty_ty Ty_String(void)
{
    Ty_ty ty = (Ty_ty)malloc(sizeof(struct Ty_ty_));
    ty->type = ty_String;
    return ty;
}

Ty_ty Ty_Nil(void)
{
    Ty_ty ty = (Ty_ty)malloc(sizeof(struct Ty_ty_));
    ty->type = ty_Nil;
    return ty;
}

Ty_ty Ty_Void(void)
{
    Ty_ty ty = (Ty_ty)malloc(sizeof(struct Ty_ty_));
    ty->type = ty_Void;
    return ty;
}

Ty_ty Ty_Record(Ty_fieldList fields)
{
    Ty_ty ty = (Ty_ty)malloc(sizeof(struct Ty_ty_));
    ty->type = ty_Record;
    ty->u.record = fields;
    return ty;
}

Ty_ty Ty_Array(Ty_ty ty_array)
{
    Ty_ty ty = (Ty_ty)malloc(sizeof(struct Ty_ty_));
    ty->type = ty_Array;
    ty->u.array = ty_array;
}

Ty_ty Ty_Name(symbol sym, Ty_ty ty_name)
{
    Ty_ty ty = (Ty_ty)malloc(sizeof(struct Ty_ty_));
    ty->type = ty_Name;
    ty->u.name.sym = sym;
    ty->u.name.ty = ty_name;
    return ty;
}

/* constructors for other internal structs */

Ty_fieldList Ty_FieldList(Ty_field head, Ty_fieldList tail)
{
    Ty_fieldList tfl = (Ty_fieldList)malloc(sizeof(struct Ty_fieldList_));
    tfl->head = head;
    tfl->tail = tail;
    return tfl;
}

Ty_tyList    Ty_TyList(Ty_ty ty, Ty_tyList tail)
{
    Ty_tyList tl = (Ty_tyList)malloc(sizeof(struct Ty_tyList_));
    tl->head = ty;
    tl->tail = tail;
    return tl;
}

Ty_field     Ty_Field(symbol sym, Ty_ty ty)
{
    Ty_field tf = (Ty_field)malloc(sizeof(struct Ty_field_));
    tf->sym = sym;
    tf->ty = ty;
    return tf;
}

/* end of types.c */

