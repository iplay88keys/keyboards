enum macro_id {
    M_GINKGO,
    M_DESCRIBE,
    M_CONTEXT,
    M_IT,
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt __attribute__ ((unused)))
{
    switch (id) {
	    case (M_GINKGO):
	        return MACRO( \
			    T(G), T(I), T(N), T(K), T(G), T(O), T(SPACE), \
			    T(MINS), T(R), T(SPACE), \
			    T(MINS), T(R), T(A), T(C), T(E), T(SPACE), \
			    T(MINS), T(U), T(N), T(T), T(I), T(L), \
			    D(LSFT), T(I), U(LSFT), T(T), \
			    D(LSFT), T(F), U(LSFT), T(A), T(I), T(L), T(S), T(SPACE), \
			    T(MINS), T(R), T(A), T(N), T(D), T(O), T(M), T(I), T(Z), T(E), \
			    D(LSFT), T(A), U(LSFT), T(L), T(L), \
			    D(LSFT), T(S), U(LSFT), T(P), T(E), T(C), T(S), T(ENT), END \
			    );
        case (M_DESCRIBE):
            return MACRO( \
            T(O), \
            D(LSFT), T(D), U(LSFT), T(E), T(S), T(C), T(R), T(I), T(B), T(E), \
            T(SPACE), T(ESC), END \
            );
        case (M_CONTEXT):
            return MACRO( \
            T(O), \
            D(LSFT), T(C), U(LSFT), T(O), T(N), T(T), T(E), T(X), T(T), \
            T(SPACE), T(ESC), END \
                    );
        case (M_IT):
            return MACRO( \
            T(O), \
            D(LSFT), T(I), U(LSFT), T(T), T(SPACE), T(ESC), END \
            );
    }
    return MACRO_NONE;
};
