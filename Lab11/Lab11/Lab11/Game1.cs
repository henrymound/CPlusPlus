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
using ExplodingTeddies; 

namespace Lab11
{
    /// <summary>
    /// This is the main type for your game
    /// </summary>
    public class Game1 : Microsoft.Xna.Framework.Game
    {

        //Define constants for the window dimensions
        const int WINDOW_WIDTH = 800;
        const int WINDOW_HEIGHT = 600; 
        GraphicsDeviceManager graphics;
        SpriteBatch spriteBatch;
        TeddyBear bear;
        Explosion explosion;
        Random rand = new Random();

        public Game1()
        {
            graphics = new GraphicsDeviceManager(this);
            Content.RootDirectory = "Content";
            //sets the window dimentions with the predeclared values
            graphics.PreferredBackBufferWidth = WINDOW_WIDTH;
            graphics.PreferredBackBufferHeight = WINDOW_HEIGHT; 
            //makes mouse pointer visible
            IsMouseVisible = true; 
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
            /*Declares a TeddyBear a starting position and a random velocity*/
            bear = new TeddyBear(Content, WINDOW_WIDTH, WINDOW_HEIGHT, "orange", 300, 200, new Vector2((rand.Next(5) + 2), (rand.Next(5) + 2)));
            //Creates an explosion object with the same content manager as the bear
            explosion = new Explosion(Content); 
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
            bear.Update();
            MouseState mouse = Mouse.GetState();
            if ((mouse.LeftButton == ButtonState.Pressed)&&
                (//Only triggers an explosion if a person presses the left mouse button withing 40 pixels of the center of the bear
                    ((mouse.X < (bear.DrawRectangle.Center.X + 20)) && (mouse.X > (bear.DrawRectangle.Center.X - 20)))&&
                    ((mouse.Y < (bear.DrawRectangle.Center.Y + 20)) && (mouse.Y > (bear.DrawRectangle.Center.Y - 20)))
                 )
                ) { // make teddy bear disappear and start the explosion explosion.
                explosion.Play(bear.DrawRectangle.Center.X, bear.DrawRectangle.Center.Y);
                bear.Active = false;
                bear = new TeddyBear(Content, WINDOW_WIDTH, WINDOW_HEIGHT, "orange", 300, 200, new Vector2((rand.Next(5) + 2), (rand.Next(5) + 2)));
            }
            //updates explosion when it is being animated
            explosion.Update(gameTime);
            base.Update(gameTime);
        }

        /// <summary>
        /// This is called when the game should draw itself.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Draw(GameTime gameTime)
        {
            GraphicsDevice.Clear(Color.PaleGreen);
            //code to draw the bear and explosion using spriteBatch, spriteBatch then terminates itself after drawing.
            spriteBatch.Begin();
            bear.Draw(spriteBatch);
            explosion.Draw(spriteBatch);
            spriteBatch.End();
            base.Draw(gameTime);
        }
    }
}
