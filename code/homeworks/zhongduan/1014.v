module top(
    input clk,
    input rst,
    input INT_irq,
    input INT_fiq,
    input [31:0] IR,
    input [31:0] CPSR,
    
    output reg Write_Reg,
    output reg Write_PC,
    output reg Write_IR,
    output reg Write_CPSR,
    output reg Write_SPSR,
    output reg S,
    output reg SP_in,
    output reg SP_out,
    output reg W_SPSR_s,
    output reg INTA_irq,
    output reg INTA_fiq,
    output reg [1:0] W_Rdata_s,
    output reg [1:0] rd_s,
    output reg [1:0] ALU_A_s,
    output reg [2:0] W_CPSR_s,
    output reg [2:0] Change_M,
    output reg [3:0] PC_s,
    output reg [3:0] ALU_OP

    );
    reg [5:0] ST,Next_ST;
    
    parameter 
        Idle = 6'b000000,
        S0 = 6'b000001,
        S1 = 6'b000010,
        S2 = 6'b000011,
        S3 = 6'b000100,
        S4 = 6'b000101,
        S19 = 6'b010100,
        S20 = 6'b010101,
        S21 = 6'b010110,
        S22 = 6'b010111,
        S26 = 6'b011011,
        S27 = 6'b011100,
        S28 = 6'b011101,
        S29 = 6'b011110,
        S30 = 6'b011111,
        S31 = 6'b100000,
        S32 = 6'b100001;
    
    always @(posedge rst or posedge clk)  begin
	  if (rst) ST <= Idle;
      else  ST <= Next_ST;
    end
    
    always @(*) begin	
        Next_ST = Idle;
        case (ST)
            Idle: Next_ST = S0;
            S0: Next_ST = S1;
                 //´ÎÌ¬µÄ×èÈûÊ½¸³Öµ
            S1:
                if(IR[3:0] == 4'he)
                     Next_ST = S28;
                 else
                    Next_ST = S0;
            S4: Next_ST = S29;
            S26: Next_ST = S27;
            S27: 
                if((INT_irq == 1 && CPSR[7] == 0) || (INT_fiq == 1 && CPSR[6] == 0) ) 
                    Next_ST = S29;
                else
                    Next_ST = S0;
            S28: Next_ST = S26;
            S29: Next_ST = S30;
            S30: Next_ST = S31;
            S31: Next_ST = S32;
            S32: Next_ST = S0;
            default:  Next_ST = S0; 
        endcase
    end
    
    
    always @(posedge rst or posedge clk) begin
        if (rst) begin
            Write_Reg <= 0;
            Write_PC <= 0;
            Write_IR <= 0;
            Write_CPSR <= 0;
            Write_SPSR <= 0;
            S <= 0;
            SP_in <= 0;
            SP_out <= 0;
            W_SPSR_s <= 0;
            INTA_irq <= 0;
            INTA_fiq <= 0;
            W_Rdata_s <= 0;
            rd_s <= 0;
            ALU_A_s <= 0;
            W_CPSR_s <= 0;
            Change_M <= 0;
            PC_s <= 0;
            ALU_OP <= 0;
        end
        else
            Write_Reg <= 0;
            Write_PC <= 0;
            Write_IR <= 0;
            Write_CPSR <= 0;
            Write_SPSR <= 0;
            S <= 0;
            SP_in <= 0;
            SP_out <= 0;
            W_SPSR_s <= 0;
            INTA_irq <= 0;
            INTA_fiq <= 0;
            W_Rdata_s <= 0;
            rd_s <= 0;
            ALU_A_s <= 0;
            W_CPSR_s <= 0;
            Change_M <= 0;
            PC_s <= 0;
            ALU_OP <= 0;
            
            case(Next_ST)
                S0: begin
                    Write_PC <= 1;
                    PC_s <= 3'b000;
                    Write_IR <= 1;
                end
                S1:;
                S26: begin
                   W_Rdata_s <= 0;
                   Write_CPSR <= 1;
                   W_CPSR_s <= 0;
                   S <= 0;
                   PC_s <= 2'b01;
                   SP_out <= 1;
                end
                S27: begin
                    SP_in <= 1;
                end
                S28: begin //MOVS
                   ALU_OP <= 4'b1000; 
                   S <= 1;
                end
                S29: begin
                    ALU_OP <= 4'b1000;
                    ALU_A_s <= 2'b01;
                end
                S30: begin
                    if(INT_fiq ==1 && CPSR[6] == 0) begin
                        Change_M <= 3'b010;
                        W_Rdata_s <= 0;
                        rd_s <= 1;
                        Write_Reg <= 1;
                        Write_SPSR <= 1;
                        W_SPSR_s <= 1;
                    end
                    else begin
                        Change_M <= 3'b001;
                        W_Rdata_s <= 0;
                        rd_s <= 1;
                        Write_Reg <= 1;
                        Write_SPSR <= 1;
                        W_SPSR_s <= 1;
                    end
                end
                S31: begin
                    if(INT_fiq ==1 && CPSR[6] == 0) begin
                        Change_M <= 3'b001;
                        W_CPSR_s <= 3'b011;
                        INTA_fiq <= 1;
                    end
                    else begin
                        Change_M <= 3'b000;
                        W_CPSR_s <= 3'b010;
                        INTA_irq <= 1;
                    end
                    PC_s <= 2'b11;
                    SP_out <= 1;
                end
                S32: begin
                    SP_in <= 1;
                end
            endcase
    end
endmodule