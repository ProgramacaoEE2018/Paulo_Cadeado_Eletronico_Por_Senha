namespace JanelaDoProjeto
{
    partial class Senha
    {
        /// <summary>
        /// Variável de designer necessária.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpar os recursos que estão sendo usados.
        /// </summary>
        /// <param name="disposing">true se for necessário descartar os recursos gerenciados; caso contrário, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código gerado pelo Windows Form Designer

        /// <summary>
        /// Método necessário para suporte ao Designer - não modifique 
        /// o conteúdo deste método com o editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.Digito2 = new System.Windows.Forms.Button();
            this.Digito1 = new System.Windows.Forms.Button();
            this.Confirma = new System.Windows.Forms.Button();
            this.Visor = new System.Windows.Forms.Panel();
            this.SuspendLayout();
            // 
            // Digito2
            // 
            this.Digito2.BackColor = System.Drawing.Color.Black;
            this.Digito2.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.Digito2.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Digito2.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.Digito2.Location = new System.Drawing.Point(679, 126);
            this.Digito2.Name = "Digito2";
            this.Digito2.Size = new System.Drawing.Size(81, 67);
            this.Digito2.TabIndex = 0;
            this.Digito2.Text = "1";
            this.Digito2.UseVisualStyleBackColor = false;
            // 
            // Digito1
            // 
            this.Digito1.BackColor = System.Drawing.Color.Black;
            this.Digito1.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.Digito1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Digito1.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.Digito1.Location = new System.Drawing.Point(525, 126);
            this.Digito1.Name = "Digito1";
            this.Digito1.Size = new System.Drawing.Size(81, 67);
            this.Digito1.TabIndex = 1;
            this.Digito1.Text = "0";
            this.Digito1.UseVisualStyleBackColor = false;
            // 
            // Confirma
            // 
            this.Confirma.BackColor = System.Drawing.Color.Black;
            this.Confirma.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.Confirma.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Confirma.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.Confirma.Location = new System.Drawing.Point(601, 268);
            this.Confirma.Name = "Confirma";
            this.Confirma.Size = new System.Drawing.Size(81, 67);
            this.Confirma.TabIndex = 2;
            this.Confirma.Text = "Enter";
            this.Confirma.UseVisualStyleBackColor = false;
            // 
            // Visor
            // 
            this.Visor.BackColor = System.Drawing.Color.White;
            this.Visor.Location = new System.Drawing.Point(93, 173);
            this.Visor.Name = "Visor";
            this.Visor.Size = new System.Drawing.Size(301, 108);
            this.Visor.TabIndex = 3;
            // 
            // Senha
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.MidnightBlue;
            this.ClientSize = new System.Drawing.Size(898, 475);
            this.Controls.Add(this.Visor);
            this.Controls.Add(this.Confirma);
            this.Controls.Add(this.Digito1);
            this.Controls.Add(this.Digito2);
            this.Name = "Senha";
            this.Text = "Cadeado";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button Digito2;
        private System.Windows.Forms.Button Digito1;
        private System.Windows.Forms.Button Confirma;
        private System.Windows.Forms.Panel Visor;
    }
}

