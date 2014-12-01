using System;
using System.Collections.Generic;
using System.Linq;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Audio;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.GamerServices;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Media;

namespace Lab17
{
    /// <summary>
    /// This is the main type for your game
    /// </summary>
    public class Game1 : Microsoft.Xna.Framework.Game
    {
        GraphicsDeviceManager graphics;
        SpriteBatch spriteBatch;

        Texture2D spriteTexture;
        Rectangle spriteRectangle;

        const int WINDOW_WIDTH = 800;
        const int WINDOW_HEIGHT = 600; 

        //how many pixels your asset will move on each update
        const int PIXELS_TO_MOVE = 5;
        //counts how many times the sprite goes off screen
        int offScreenCount = 0;
        //Creates SpriteFont to display count
        SpriteFont spriteFont;
        Vector2 spriteFontVectorscorePosition = new Vector2(10, 10);

        public Game1()
        {
            graphics = new GraphicsDeviceManager(this);
            Content.RootDirectory = "Content";

            graphics.PreferredBackBufferWidth = WINDOW_WIDTH;
            graphics.PreferredBackBufferHeight = WINDOW_HEIGHT;
        }

        /// <summary>
        /// Allows the game to perform any initialization it needs to before starting to run.
        /// This is where it can query for any required services and load any non-graphic
        /// related content.  Calling base.Initialize will enumerate through any components
        /// and initialize them as well.
        /// </summary>
        protected override void Initialize()
        {
            // TODO: Add your initialization logic here

            base.Initialize();
        }

        /// <summary>
        /// LoadContent will be called once per game and is the place to load
        /// all of your content.
        /// </summary>
        protected override void LoadContent()
        {
            // Create a new SpriteBatch, which can be used to draw textures.
            spriteBatch = new SpriteBatch(GraphicsDevice);
            spriteTexture = Content.Load<Texture2D>("sprite");
            spriteRectangle = new Rectangle(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 50, 62);
            // load sprite font
            spriteFont = Content.Load<SpriteFont>("Arial");
        }

        /// <summary>
        /// UnloadContent will be called once per game and is the place to unload
        /// all content.
        /// </summary>
        protected override void UnloadContent()
        {
            // TODO: Unload any non ContentManager content here
        }

        /// <summary>
        /// Allows the game to run logic such as updating the world,
        /// checking for collisions, gathering input, and playing audio.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Update(GameTime gameTime)
        {
            // Allows the game to exit
            if (GamePad.GetState(PlayerIndex.One).Buttons.Back == ButtonState.Pressed)
                this.Exit();

            //controls movement using constant speed either with WASD or arrow key controls
            if ((Keyboard.GetState().IsKeyDown(Keys.A)) || (Keyboard.GetState().IsKeyDown(Keys.Left)))
                spriteRectangle.X -= PIXELS_TO_MOVE;

            if ((Keyboard.GetState().IsKeyDown(Keys.D)) || (Keyboard.GetState().IsKeyDown(Keys.Right)))
                spriteRectangle.X += PIXELS_TO_MOVE;

            if ((Keyboard.GetState().IsKeyDown(Keys.W)) || (Keyboard.GetState().IsKeyDown(Keys.Up)))
                spriteRectangle.Y -= PIXELS_TO_MOVE;

            if ((Keyboard.GetState().IsKeyDown(Keys.D)) || (Keyboard.GetState().IsKeyDown(Keys.Down)))
                spriteRectangle.Y += PIXELS_TO_MOVE;

            //centers sprite if space is pressed
            if (Keyboard.GetState().IsKeyDown(Keys.Space))
            {
                spriteRectangle.Y = WINDOW_HEIGHT / 2;
                spriteRectangle.X = WINDOW_WIDTH / 2;
            }

            //Adds to counter is sprite is off stage
            if (spriteRectangle.X > WINDOW_WIDTH || spriteRectangle.X < 0
               || spriteRectangle.Y > WINDOW_HEIGHT || spriteRectangle.Y < 0)
                 offScreenCount++;
            
            base.Update(gameTime);
        }

        /// <summary>
        /// This is called when the game should draw itself.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Draw(GameTime gameTime)
        {
            GraphicsDevice.Clear(Color.PeachPuff);
            spriteBatch.Begin();
            //draws sprite
            spriteBatch.Draw(spriteTexture, spriteRectangle, Color.White);
            //draws spriteFont to display how many times the sprite leaves the stage
            spriteBatch.DrawString(spriteFont, "Score: "+offScreenCount, spriteFontVectorscorePosition, Color.Black);
            spriteBatch.End();

            base.Draw(gameTime);
        }
    }
}
