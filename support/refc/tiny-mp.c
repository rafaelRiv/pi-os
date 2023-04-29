/* MPZ interface */
void
mpz_init (mpz_t r)
{
  static const mp_limb_t dummy_limb = GMP_LIMB_MAX & 0xc1a0;

  r->_mp_alloc = 0;
  r->_mp_size = 0;
  r->_mp_d = (mp_ptr) &dummy_limb;
}

void
mpz_clear (mpz_t r)
{
  if (r->_mp_alloc)
    gmp_free (r->_mp_d);
}

