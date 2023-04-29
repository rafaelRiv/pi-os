typedef unsigned long mp_limb_t;

typedef mp_limb_t *mp_ptr;

typedef struct
{
  int _mp_alloc;		/* Number of *limbs* allocated and pointed
				   to by the _mp_d field.  */
  int _mp_size;			/* abs(_mp_size) is the number of limbs the
				   last field points to.  If _mp_size is
				   negative this is a negative number.  */
  mp_limb_t *_mp_d;		/* Pointer to the limbs.  */
} __mpz_struct;

typedef __mpz_struct mpz_t[1];

void mpz_init (mpz_t);
void mpz_set_si (mpz_t, signed long int);
int mpz_set_str (mpz_t, const char *, int);

