enum macro_id {
    M_GINKGO,
    M_DESCRIBE,
    M_CONTEXT,
    M_IT,
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt __attribute__ ((unused)))
{
    if (record->event.pressed) {
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
                D(LSFT), T(D), U(LSFT), T(E), T(S), T(C), T(R), T(I), T(B), T(E), \
                D(LSFT), T(9), T(0), U(LSFT), T(LEFT), D(LSFT), T(QUOTE), T(QUOTE), \
                U(LSFT), T(COMMA), T(SPACE), T(F), T(U), T(N), T(C), D(LSFT), T(9), \
                T(0), U(LSFT), T(SPACE), D(LSFT), T(LBRC), T(RBRC), U(LSFT), T(LEFT), \
                T(ENT), T(UP), T(RIGHT), T(RIGHT), T(RIGHT), T(RIGHT), T(RIGHT), \
                T(RIGHT), T(RIGHT), T(RIGHT), T(RIGHT), T(RIGHT), END \
                );
            case (M_CONTEXT):
                return MACRO( \
                D(LSFT), T(C), U(LSFT), T(O), T(N), T(T), T(E), T(X), T(T), \
                D(LSFT), T(9), T(0), U(LSFT), T(LEFT), D(LSFT), T(QUOTE), T(QUOTE), \
                U(LSFT), T(COMMA), T(SPACE), T(F), T(U), T(N), T(C), D(LSFT), T(9), \
                T(0), U(LSFT), T(SPACE), D(LSFT), T(LBRC), T(RBRC), U(LSFT), T(LEFT), \
                T(ENT), T(UP), T(RIGHT), T(RIGHT), T(RIGHT), T(RIGHT), T(RIGHT), \
                T(RIGHT), T(RIGHT), T(RIGHT), T(RIGHT), END \
                );
            case (M_IT):
                return MACRO( \
                D(LSFT), T(I), U(LSFT), T(T), \
                D(LSFT), T(9), T(0), U(LSFT), T(LEFT), D(LSFT), T(QUOTE), T(QUOTE), \
                U(LSFT), T(COMMA), T(SPACE), T(F), T(U), T(N), T(C), D(LSFT), T(9), \
                T(0), U(LSFT), T(SPACE), D(LSFT), T(LBRC), T(RBRC), U(LSFT), T(LEFT), \
                T(ENT), T(UP), T(RIGHT), T(RIGHT), T(RIGHT), T(RIGHT), END \
                );
        }
    }
    return MACRO_NONE;
};
