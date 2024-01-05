module gates (
    input a, b,
    output x, y, z
);
    and(x, a, b);
    or(y, a, b);
    not(z, x);
endmodule

module gates_test();
    reg a, b;
    wire x, y, z;
    gates gates(
        .a(a), .b(b), .x(x), .y(y), .z(z)
    );
    initial begin
        a = 0;
        b = 0;
        #10 a = 1;
        #10 b = 1;
        #10 a = 0;
        #10 b = 0;
        #10 $finish;
    end
endmodule
