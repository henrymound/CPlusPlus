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

namespace Lab5
{
    /// <summary>
    /// This is the main type for your game
    /// </summary>
    public class Game1 : Microsoft.Xna.Framework.Game
    {
        GraphicsDeviceManager graphics;
        SpriteBatch spriteBatch;

        Texture2D orangeSprite;
        Texture2D blueSprite;
        Texture2D greenSprite;

        Rectangle drawRectangle1;
        Rectangle drawRectangle2;
        Rectangle drawRectangle3;

        const int WINDOW_HEIGHT = 800;
        const int WINDOW_WIDTH = 600;

        public Game1()
        {
            graphics = new GraphicsDeviceManager(this);
            Content.RootDirectory = "Content";
            graphics.PreferredBackBufferWidth = 584;
            graphics.PreferredBackBufferHeight = 438;
            
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

            //load photo sprites
            orangeSprite = Content.Load<Texture2D>("orange");
            greenSprite = Content.Load<Texture2D>("green");
            blueSprite = Content.Load<Texture2D>("blue");

            //DRAW RECTANGLES WITH PHOTOS
            //rectangle 1 displays orange sprite at full resolution at coordinates (350, 100)
            drawRectangle1 = new Rectangle(
                350,
                100,
                orangeSprite.Width,
                orangeSprite.Height);

            //rectangle 2 displays green sprite at full resolution at coordinates (250, 100)
            drawRectangle2 = new Rectangle(
                250,
                100,
                greenSprite.Width,
                greenSprite.Height);

            //rectangle 3 displays blue sprite at full resolution at coordinates (150, 100)
            drawRectangle3 = new Rectangle(
                150,
                100,
                blueSprite.Width,
                blueSprite.Height);

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


            base.Update(gameTime);
        }

        /// <summary>
        /// This is called when the game should draw itself.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Draw(GameTime gameTime)
        {
            GraphicsDevice.Clear(Color.BurlyWood);

            spriteBatch.Begin(); 
            spriteBatch.Draw(orangeSprite, drawRectangle1, Color.White); 
            spriteBatch.Draw(greenSprite, drawRectangle2, Color.White); 
            spriteBatch.Draw(blueSprite, drawRectangle3, Color.White); 
            spriteBatch.End();

            base.Draw(gameTime);
        }
    }
}
